#ifndef L1TRC_L1D_3RD_DEF_H
#define L1TRC_L1D_3RD_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1D_Trace_Str_TM_Sync_State(v1)  (unsigned char)(v1+0)
#define L1SM_Str_Wakeup(v1)  (unsigned char)(v1+2)
#define L1SM_Str_Bool(v1)  (unsigned char)(v1+13)
#define L1SM_Disable_Bool(v1)  (unsigned char)(v1+15)
#define L1D_Dual_Afc_L1C_Ask_Msg(v1)  (unsigned char)(v1+17)
#define L1D_Trc_AFC_status(v1)  (unsigned char)(v1+27)
#define L1D_Trc_Str_NonSync_HO(v1)  (unsigned char)(v1+31)
#define L1D_Trc_Str_WGG_Event(v1)  (unsigned char)(v1+36)
#define L1D_Trc_Str_TDDM_SetGap(v1)  (unsigned char)(v1+38)
#define L1D_Trc_Str_TDDM_PM(v1)  (unsigned char)(v1+41)
#define L1D_Trc_Str_TDDM_STATE(v1)  (unsigned char)(v1+44)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0034, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define XO_TRACE_VTuneCrt7AREA(v1, v2, v3, v4)
#endif
#define XO_TRACE_VTuneCrt7AREA_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0034, (short)(v3)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_FreqCrtUpdate(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0134, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define XO_TRACE_FreqCrtUpdate(v1, v2)
#endif
#define XO_TRACE_FreqCrtUpdate_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0134, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_ReadTempADC(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0234, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define XO_TRACE_ReadTempADC(v1, v2)
#endif
#define XO_TRACE_ReadTempADC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0234, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_CmpTempPhi(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0334, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define XO_TRACE_CmpTempPhi(v1)
#endif
#define XO_TRACE_CmpTempPhi_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0334, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define XO_TRACE_Phi2Dac(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0434, (short)(v2)), (long)(v1));\
	} while(0)
#else
	#define XO_TRACE_Phi2Dac(v1, v2)
#endif
#define XO_TRACE_Phi2Dac_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0434, (short)(v2)), (long)(v1))

#if defined(L1_CATCHER)
	#define CH_afc_dbg(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0534, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CH_afc_dbg(v1, v2, v3, v4)
#endif
#define CH_afc_dbg_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0534, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define CH_afc_dbg2(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0634, (short)(v2)), (long)(v1), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define CH_afc_dbg2(v1, v2, v3, v4)
#endif
#define CH_afc_dbg2_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0634, (short)(v2)), (long)(v1), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define CH_afc_dbg3(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0734, (short)(v1)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define CH_afc_dbg3(v1, v2, v3, v4)
#endif
#define CH_afc_dbg3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0734, (short)(v1)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define CH_afc_dbg4(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0834, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)));\
	} while(0)
#else
	#define CH_afc_dbg4(v1, v2, v3, v4, v5)
#endif
#define CH_afc_dbg4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0834, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)))

#if defined(L1_CATCHER)
	#define CH_afc_dbg5(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0934, (short)(v1)));\
	} while(0)
#else
	#define CH_afc_dbg5(v1)
#endif
#define CH_afc_dbg5_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0934, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1D_Trc_DUAL_AFC_L1C_ask(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A34, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DUAL_AFC_L1C_ask(v1)
#endif
#define L1D_Trc_DUAL_AFC_L1C_ask_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A34, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_DUAL_AFC_DAC_Sharing(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B34, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DUAL_AFC_DAC_Sharing(v1, v2)
#endif
#define L1D_Trc_DUAL_AFC_DAC_Sharing_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B34, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_DUAL_AFC_MODE(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C34, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DUAL_AFC_MODE(v1)
#endif
#define L1D_Trc_DUAL_AFC_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C34, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trace_TM_Sync_State(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D34, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trace_TM_Sync_State(v1)
#endif
#define L1D_Trace_TM_Sync_State_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D34, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_TDDM_FCCH_1(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define L1D_TDDM_FCCH_1(v1, v2, v3, v4, v5)
#endif
#define L1D_TDDM_FCCH_1_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0E34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define L1D_TDDM_FB(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1D_TDDM_FB(v1, v2, v3)
#endif
#define L1D_TDDM_FB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define L1D_TDDM_SetGap(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1034, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_TDDM_SetGap(v1, v2, v3, v4)
#endif
#define L1D_TDDM_SetGap_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1034, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_TDDM_FBM_SHORT(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x1134, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_TDDM_FBM_SHORT(v1, v2, v3, v4, v5, v6)
#endif
#define L1D_TDDM_FBM_SHORT_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x1134, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_TDDM_SBM(v1, v2, v3, v4) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1234, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_TDDM_SBM(v1, v2, v3, v4)
#endif
#define L1D_TDDM_SBM_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1234, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_TDDM_PM(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1334, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_TDDM_PM(v1, v2, v3)
#endif
#define L1D_TDDM_PM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1334, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_MM_STATE(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1434, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1D_MM_STATE(v1, v2)
#endif
#define L1D_MM_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1434, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define L1D_TDDM_AFC_CON(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1534, (short)(v1)));\
	} while(0)
#else
	#define L1D_TDDM_AFC_CON(v1)
#endif
#define L1D_TDDM_AFC_CON_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1534, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L1D_Trc_RepeatedACCH(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1634, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)));\
	} while(0)
#else
	#define L1D_Trc_RepeatedACCH(v1, v2, v3, v4, v5, v6)
#endif
#define L1D_Trc_RepeatedACCH_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1634, (unsigned char)(v1), (char)(v2)), TRC_MERGE_4C((char)(v3), (unsigned char)(v4), (unsigned char)(v5), (char)(v6)))

#if defined(L1_CATCHER)
	#define L1D_TRC_DEBUG(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1734, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define L1D_TRC_DEBUG(v1, v2, v3)
#endif
#define L1D_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1734, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define L1D_TRC_DEBUG_2(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x40)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x1834, (unsigned short)(v1)), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L1D_TRC_DEBUG_2(v1, v2, v3)
#endif
#define L1D_TRC_DEBUG_2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x1834, (unsigned short)(v1)), (long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_DTS_TRACE_MACHINE(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1934, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1D_DTS_TRACE_MACHINE(v1, v2, v3)
#endif
#define L1D_DTS_TRACE_MACHINE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1934, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define L1D_TRC_NonSync_HO_Event(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[2]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A34, (unsigned char)(v1), (char)(v2)));\
	} while(0)
#else
	#define L1D_TRC_NonSync_HO_Event(v1, v2)
#endif
#define L1D_TRC_NonSync_HO_Event_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A34, (unsigned char)(v1), (char)(v2)))

#if defined(L1_CATCHER)
	#define L1D_Trc_WGG_Event(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B34, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_WGG_Event(v1)
#endif
#define L1D_Trc_WGG_Event_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B34, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_WGG_ConsumePMQueue(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C34, (short)(v1)));\
	} while(0)
#else
	#define L1D_Trc_WGG_ConsumePMQueue(v1)
#endif
#define L1D_Trc_WGG_ConsumePMQueue_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C34, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_WCAL_RESULT(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x20)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D34, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_WCAL_RESULT(v1, v2, v3)
#endif
#define L1D_Trc_WCAL_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D34, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_HRD_POWER_RESULT(v1, v2, v3) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1D_Trc_HRD_POWER_RESULT(v1, v2, v3)
#endif
#define L1D_Trc_HRD_POWER_RESULT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1E34, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1D_Trc_HRD_RESULT(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F34, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_HRD_RESULT(v1)
#endif
#define L1D_Trc_HRD_RESULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1F34, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_VAMOS_RESULT(v1, v2, v3, v4, v5) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x2034, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_VAMOS_RESULT(v1, v2, v3, v4, v5)
#endif
#define L1D_Trc_VAMOS_RESULT_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x2034, (short)(v2)), TRC_MERGE_2S((short)(v3), (short)(v4)), TRC_MERGE_1S2C((short)(v5), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_BLK_RESULT(v1) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2134, (short)(v1)));\
	} while(0)
#else
	#define L1D_Trc_BLK_RESULT(v1)
#endif
#define L1D_Trc_BLK_RESULT_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2134, (short)(v1)))

#if defined(L1_CATCHER)
	#define L1D_Trc_DLIF_SWITCH_IF(v1, v2) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x2234, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DLIF_SWITCH_IF(v1, v2)
#endif
#define L1D_Trc_DLIF_SWITCH_IF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x2234, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_DLIF_PEER_IF(v1, v2, v3, v4, v5, v6) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2334, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1D_Trc_DLIF_PEER_IF(v1, v2, v3, v4, v5, v6)
#endif
#define L1D_Trc_DLIF_PEER_IF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2334, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_1S2C((short)(v6), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define L1D_Trc_DLIF_RETURN_IF(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2434, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)));\
	} while(0)
#else
	#define L1D_Trc_DLIF_RETURN_IF(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1D_Trc_DLIF_RETURN_IF_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2434, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_2S((short)(v4), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v7)))

#if defined(L1_CATCHER)
	#define L1D_TAS_TRC(v1, v2, v3, v4, v5, v6, v7) do {\
		if(L1D_3RD_Trace_Filter[0]==1 && (L1D_3RD_Trace_Filter[3]&0x40)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x2534, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)));\
	} while(0)
#else
	#define L1D_TAS_TRC(v1, v2, v3, v4, v5, v6, v7)
#endif
#define L1D_TAS_TRC_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_4_DATA(TRC_MERGE_2S(0x2534, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_2S((unsigned short)(v4), (unsigned short)(v5)), TRC_MERGE_2S((unsigned short)(v6), (unsigned short)(v7)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1D_3RD_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_XO_TRACE_VTuneCrt7AREA(char v1, long v2, short v3, long v4);
void L1TRC_Send_XO_TRACE_FreqCrtUpdate(char v1, short v2);
void L1TRC_Send_XO_TRACE_ReadTempADC(short v1, long v2);
void L1TRC_Send_XO_TRACE_CmpTempPhi(long v1);
void L1TRC_Send_XO_TRACE_Phi2Dac(long v1, short v2);
void L1TRC_Send_CH_afc_dbg(short v1, short v2, long v3, long v4);
void L1TRC_Send_CH_afc_dbg2(long v1, short v2, long v3, long v4);
void L1TRC_Send_CH_afc_dbg3(short v1, long v2, long v3, short v4);
void L1TRC_Send_CH_afc_dbg4(short v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_CH_afc_dbg5(short v1);
void L1TRC_Send_L1D_Trc_DUAL_AFC_L1C_ask(unsigned char v1);
void L1TRC_Send_L1D_Trc_DUAL_AFC_DAC_Sharing(short v1, unsigned char v2);
void L1TRC_Send_L1D_Trc_DUAL_AFC_MODE(unsigned char v1);
void L1TRC_Send_L1D_Trace_TM_Sync_State(unsigned char v1);
void L1TRC_Send_L1D_TDDM_FCCH_1(short v1, short v2, short v3, long v4, long v5);
void L1TRC_Send_L1D_TDDM_FB(short v1, short v2, short v3);
void L1TRC_Send_L1D_TDDM_SetGap(unsigned char v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_TDDM_FBM_SHORT(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_TDDM_SBM(short v1, short v2, short v3, short v4);
void L1TRC_Send_L1D_TDDM_PM(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1D_MM_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1D_TDDM_AFC_CON(short v1);
void L1TRC_Send_L1D_Trc_RepeatedACCH(unsigned char v1, char v2, char v3, unsigned char v4, unsigned char v5, char v6);
void L1TRC_Send_L1D_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_L1D_TRC_DEBUG_2(unsigned short v1, long v2, unsigned long v3);
void L1TRC_Send_L1D_DTS_TRACE_MACHINE(short v1, short v2, short v3);
void L1TRC_Send_L1D_TRC_NonSync_HO_Event(unsigned char v1, char v2);
void L1TRC_Send_L1D_Trc_WGG_Event(unsigned char v1);
void L1TRC_Send_L1D_Trc_WGG_ConsumePMQueue(short v1);
void L1TRC_Send_L1D_Trc_WCAL_RESULT(char v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_HRD_POWER_RESULT(short v1, short v2, short v3);
void L1TRC_Send_L1D_Trc_HRD_RESULT(char v1);
void L1TRC_Send_L1D_Trc_VAMOS_RESULT(unsigned char v1, short v2, short v3, short v4, short v5);
void L1TRC_Send_L1D_Trc_BLK_RESULT(short v1);
void L1TRC_Send_L1D_Trc_DLIF_SWITCH_IF(short v1, short v2);
void L1TRC_Send_L1D_Trc_DLIF_PEER_IF(short v1, short v2, short v3, short v4, short v5, short v6);
void L1TRC_Send_L1D_Trc_DLIF_RETURN_IF(short v1, short v2, short v3, short v4, short v5, short v6, short v7);
void L1TRC_Send_L1D_TAS_TRC(unsigned short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned short v5, unsigned short v6, unsigned short v7);

void Set_L1D_3RD_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1D_3RD()	(L1D_3RD_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DM_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_SM_LOCKER_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_RepeatedACCH_L()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DBG_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_FHC_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_GSM_SM_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DBG_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x40)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[2]&0x80)!=0))
#define ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x01)!=0))
#define ChkL1ClsFltr_L1D_3RD_VAMOS_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x02)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_BLK_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x04)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x08)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x10)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_WCAL_M()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x20)!=0))
#define ChkL1ClsFltr_L1D_3RD_L1D_TAS_H()	(ChkL1ModFltr_L1D_3RD()&&((L1D_3RD_Trace_Filter[3]&0x40)!=0))
#define ChkL1MsgFltr_XO_TRACE_VTuneCrt7AREA()	ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()
#define ChkL1MsgFltr_XO_TRACE_FreqCrtUpdate()	ChkL1ClsFltr_L1D_3RD_XO_VTUNE_L()
#define ChkL1MsgFltr_XO_TRACE_ReadTempADC()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_XO_TRACE_CmpTempPhi()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_XO_TRACE_Phi2Dac()	ChkL1ClsFltr_L1D_3RD_XO_TEMP_L()
#define ChkL1MsgFltr_CH_afc_dbg()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg2()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg3()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg4()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_CH_afc_dbg5()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trc_DUAL_AFC_L1C_ask()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trc_DUAL_AFC_DAC_Sharing()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trc_DUAL_AFC_MODE()	ChkL1ClsFltr_L1D_3RD_Dual_afc_dbg_H()
#define ChkL1MsgFltr_L1D_Trace_TM_Sync_State()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FCCH_1()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FB()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_SetGap()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_FBM_SHORT()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_SBM()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_PM()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_MM_STATE()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_TDDM_AFC_CON()	ChkL1ClsFltr_L1D_3RD_L1D_DM_H()
#define ChkL1MsgFltr_L1D_Trc_RepeatedACCH()	ChkL1ClsFltr_L1D_3RD_L1D_RepeatedACCH_L()
#define ChkL1MsgFltr_L1D_TRC_DEBUG()	ChkL1ClsFltr_L1D_3RD_L1D_DBG_H()
#define ChkL1MsgFltr_L1D_TRC_DEBUG_2()	ChkL1ClsFltr_L1D_3RD_L1D_DBG_H()
#define ChkL1MsgFltr_L1D_DTS_TRACE_MACHINE()	ChkL1ClsFltr_L1D_3RD_L1D_FHC_M()
#define ChkL1MsgFltr_L1D_TRC_NonSync_HO_Event()	ChkL1ClsFltr_L1D_3RD_L1D_Improve_HO_H()
#define ChkL1MsgFltr_L1D_Trc_WGG_Event()	ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()
#define ChkL1MsgFltr_L1D_Trc_WGG_ConsumePMQueue()	ChkL1ClsFltr_L1D_3RD_GEMINI_WGG_H()
#define ChkL1MsgFltr_L1D_Trc_WCAL_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_WCAL_M()
#define ChkL1MsgFltr_L1D_Trc_HRD_POWER_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()
#define ChkL1MsgFltr_L1D_Trc_HRD_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_M()
#define ChkL1MsgFltr_L1D_Trc_VAMOS_RESULT()	ChkL1ClsFltr_L1D_3RD_VAMOS_H()
#define ChkL1MsgFltr_L1D_Trc_BLK_RESULT()	ChkL1ClsFltr_L1D_3RD_L1D_BLK_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_SWITCH_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_PEER_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()
#define ChkL1MsgFltr_L1D_Trc_DLIF_RETURN_IF()	ChkL1ClsFltr_L1D_3RD_L1D_DLIF_H()
#define ChkL1MsgFltr_L1D_TAS_TRC()	ChkL1ClsFltr_L1D_3RD_L1D_TAS_H()


#endif
