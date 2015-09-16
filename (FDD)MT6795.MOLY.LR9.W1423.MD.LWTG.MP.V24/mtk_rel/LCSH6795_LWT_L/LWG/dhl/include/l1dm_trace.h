#ifndef L1TRC_L1DM_DEF_H
#define L1TRC_L1DM_DEF_H

/******************************/
/* String category definition */
/******************************/
#define L1DM_Str_Bool(v1)  (unsigned char)(v1+0)
#define L1DM_Str_DMState(v1)  (unsigned char)(v1+2)
#define L1DM_Str_2g_resel_mode(v1)  (unsigned char)(v1+12)
#define L1DM_Str_switch_2G_resel_mode_when(v1)  (unsigned char)(v1+14)
#define L1DM_Str_gap_purpose(v1)  (unsigned char)(v1+19)
#define L1DM_Str_pm_period(v1)  (unsigned char)(v1+25)
#define L1DM_Str_ignore_gap_cause(v1)  (unsigned char)(v1+27)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SB(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x002A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_SB(v1, v2, v3)
#endif
#define L1DM_MSG_SB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x002A, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FB(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x012A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_FB(v1, v2, v3)
#endif
#define L1DM_MSG_FB_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x012A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_IRATSYNC(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x022A, (short)(v2)), (unsigned long)(v1), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_IRATSYNC(v1, v2, v3)
#endif
#define L1DM_MSG_IRATSYNC_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x022A, (short)(v2)), (unsigned long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMCell(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x032A, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMCell(v1)
#endif
#define L1DM_MSG_PMCell_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x032A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x042A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_3GGap(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_3GGap_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_2S(0x042A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_AbortBSIC() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x052A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_AbortBSIC()
#endif
#define L1DM_MSG_AbortBSIC_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x052A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGap(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x062A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v3));\
	} while(0)
#else
	#define L1DM_MSG_2GGap(v1, v2, v3, v4)
#endif
#define L1DM_MSG_2GGap_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x062A, (short)(v2)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GGapStop() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x072A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_2GGapStop()
#endif
#define L1DM_MSG_2GGapStop_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x072A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_StartGapSchedule() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x082A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_StartGapSchedule()
#endif
#define L1DM_MSG_StartGapSchedule_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x082A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_StopGapSchedule(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x092A, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_StopGapSchedule(v1)
#endif
#define L1DM_MSG_StopGapSchedule_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x092A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_FMOLock(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A2A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_FMOLock(v1)
#endif
#define L1DM_MSG_FMOLock_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A2A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_CancelGap() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_CancelGap()
#endif
#define L1DM_MSG_CancelGap_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_Lock2G(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C2A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_Lock2G(v1)
#endif
#define L1DM_MSG_Lock2G_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0C2A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DMState(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D2A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_DMState(v1)
#endif
#define L1DM_MSG_DMState_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0D2A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E2A, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMTick(v1)
#endif
#define L1DM_MSG_PMTick_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0E2A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMTick_HPSearch(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F2A, (short)(v1)));\
	} while(0)
#else
	#define L1DM_MSG_PMTick_HPSearch(v1)
#endif
#define L1DM_MSG_PMTick_HPSearch_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0F2A, (short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMDone(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x102A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)));\
	} while(0)
#else
	#define L1DM_MSG_PMDone(v1, v2, v3)
#endif
#define L1DM_MSG_PMDone_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x102A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_DeleteGap() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x112A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_DeleteGap()
#endif
#define L1DM_MSG_DeleteGap_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x112A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GAP_STANDBY(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x122A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v8)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4), (long)(v7), (long)(v9), (long)(v11));\
	} while(0)
#else
	#define L1DM_MSG_GAP_STANDBY(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#endif
#define L1DM_MSG_GAP_STANDBY_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11) TRC_SEND_8_DATA(TRC_MERGE_2S(0x122A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v5)), TRC_MERGE_2S((short)(v6), (short)(v8)), TRC_MERGE_1S2C((short)(v10), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v4), (long)(v7), (long)(v9), (long)(v11))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x132A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)));\
	} while(0)
#else
	#define L1DM_MSG_GapType_TD(v1, v2, v3, v4)
#endif
#define L1DM_MSG_GapType_TD_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_2S(0x132A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), (unsigned char)(v4)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x142A, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v2), (long)(v5), (long)(v8));\
	} while(0)
#else
	#define L1DM_MSG_SetGap_TD(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define L1DM_MSG_SetGap_TD_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_6_DATA(TRC_MERGE_2S(0x142A, (short)(v1)), TRC_MERGE_2S((short)(v4), (short)(v7)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v6), (unsigned char)(v9), TRC_BOXSTER_PAD), (long)(v2), (long)(v5), (long)(v8))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_Ignore_gaps(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x152A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_Ignore_gaps(v1, v2, v3)
#endif
#define L1DM_MSG_Ignore_gaps_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x152A, (short)(v1)), TRC_MERGE_1S2C((short)(v2), (unsigned char)(v3), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x162A, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), (long)(v5));\
	} while(0)
#else
	#define L1DM_MSG_BSICSchedule_TD(v1, v2, v3, v4, v5)
#endif
#define L1DM_MSG_BSICSchedule_TD_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x162A, (short)(v1)), TRC_MERGE_1S2C((short)(v4), (unsigned char)(v2), (unsigned char)(v3)), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMLock_TD(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x172A, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMLock_TD(v1)
#endif
#define L1DM_MSG_PMLock_TD_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x172A, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_PMPeriod(v1, v2, v3) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x182A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_PMPeriod(v1, v2, v3)
#endif
#define L1DM_MSG_PMPeriod_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x182A, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_ReselMode_Standby(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x192A, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define L1DM_MSG_ReselMode_Standby(v1, v2)
#endif
#define L1DM_MSG_ReselMode_Standby_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x192A, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGapStart(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGapStart(v1, v2, v3, v4)
#endif
#define L1DM_MSG_2GAutoGapStart_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x1A2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGapEnd() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGapEnd()
#endif
#define L1DM_MSG_2GAutoGapEnd_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_2GAutoGAPTimer(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define L1DM_MSG_2GAutoGAPTimer(v1)
#endif
#define L1DM_MSG_2GAutoGAPTimer_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1C2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPGet(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D2A, (short)(v2)), (unsigned long)(v1));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPGet(v1, v2)
#endif
#define L1DM_MSG_GSMAutoGAPGet_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D2A, (short)(v2)), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPPut() do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPPut()
#endif
#define L1DM_MSG_GSMAutoGAPPut_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPConfirm(v1, v2) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2A, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPConfirm(v1, v2)
#endif
#define L1DM_MSG_GSMAutoGAPConfirm_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2A, (unsigned char)(v1), TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GSMAutoGAPStop(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x202A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define L1DM_MSG_GSMAutoGAPStop(v1)
#endif
#define L1DM_MSG_GSMAutoGAPStop_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x202A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_GetGSMAutoGAPLength(v1) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x212A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define L1DM_MSG_GetGSMAutoGAPLength(v1)
#endif
#define L1DM_MSG_GetGSMAutoGAPLength_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x212A, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define L1DM_MSG_LTE_Connecedt_GAP(v1, v2, v3, v4) do {\
		if(L1DM_Trace_Filter[0]==1 && (L1DM_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x222A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define L1DM_MSG_LTE_Connecedt_GAP(v1, v2, v3, v4)
#endif
#define L1DM_MSG_LTE_Connecedt_GAP_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x222A, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L1DM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L1DM_MSG_SB(short v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_L1DM_MSG_FB(short v1, short v2, unsigned char v3);
void L1TRC_Send_L1DM_MSG_IRATSYNC(unsigned long v1, short v2, long v3);
void L1TRC_Send_L1DM_MSG_PMCell(short v1);
void L1TRC_Send_L1DM_MSG_3GGap(unsigned long v1, short v2, long v3, short v4, unsigned char v5);
void L1TRC_Send_L1DM_MSG_AbortBSIC(void);
void L1TRC_Send_L1DM_MSG_2GGap(unsigned long v1, short v2, long v3, short v4);
void L1TRC_Send_L1DM_MSG_2GGapStop(void);
void L1TRC_Send_L1DM_MSG_StartGapSchedule(void);
void L1TRC_Send_L1DM_MSG_StopGapSchedule(short v1);
void L1TRC_Send_L1DM_MSG_FMOLock(unsigned char v1);
void L1TRC_Send_L1DM_MSG_CancelGap(void);
void L1TRC_Send_L1DM_MSG_Lock2G(unsigned char v1);
void L1TRC_Send_L1DM_MSG_DMState(unsigned char v1);
void L1TRC_Send_L1DM_MSG_PMTick(short v1);
void L1TRC_Send_L1DM_MSG_PMTick_HPSearch(short v1);
void L1TRC_Send_L1DM_MSG_PMDone(short v1, short v2, short v3);
void L1TRC_Send_L1DM_MSG_DeleteGap(void);
void L1TRC_Send_L1DM_MSG_GAP_STANDBY(short v1, short v2, unsigned char v3, unsigned long v4, short v5, short v6, long v7, short v8, long v9, short v10, long v11);
void L1TRC_Send_L1DM_MSG_GapType_TD(unsigned char v1, short v2, short v3, unsigned char v4);
void L1TRC_Send_L1DM_MSG_SetGap_TD(short v1, long v2, unsigned char v3, short v4, long v5, unsigned char v6, short v7, long v8, unsigned char v9);
void L1TRC_Send_L1DM_MSG_Ignore_gaps(short v1, short v2, unsigned char v3);
void L1TRC_Send_L1DM_MSG_BSICSchedule_TD(short v1, unsigned char v2, unsigned char v3, short v4, long v5);
void L1TRC_Send_L1DM_MSG_PMLock_TD(unsigned char v1);
void L1TRC_Send_L1DM_MSG_PMPeriod(unsigned char v1, short v2, short v3);
void L1TRC_Send_L1DM_MSG_ReselMode_Standby(unsigned char v1, unsigned char v2);
void L1TRC_Send_L1DM_MSG_2GAutoGapStart(long v1, long v2, long v3, long v4);
void L1TRC_Send_L1DM_MSG_2GAutoGapEnd(void);
void L1TRC_Send_L1DM_MSG_2GAutoGAPTimer(long v1);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPGet(unsigned long v1, short v2);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPPut(void);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPConfirm(unsigned char v1, long v2);
void L1TRC_Send_L1DM_MSG_GSMAutoGAPStop(unsigned long v1);
void L1TRC_Send_L1DM_MSG_GetGSMAutoGAPLength(long v1);
void L1TRC_Send_L1DM_MSG_LTE_Connecedt_GAP(short v1, short v2, short v3, unsigned short v4);

void Set_L1DM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L1DM()	(L1DM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L1DM_DMBSIC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L1DM_DMSYNC_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_L1DM_DMPM_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_L1DM_DMGAP_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_L1DM_DMTick_M()	(ChkL1ModFltr_L1DM()&&((L1DM_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_L1DM_MSG_SB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_FB()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_IRATSYNC()	ChkL1ClsFltr_L1DM_DMSYNC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMCell()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_3GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_AbortBSIC()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GGapStop()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_StartGapSchedule()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_StopGapSchedule()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_FMOLock()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_CancelGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_Lock2G()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_DMState()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMTick_HPSearch()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMDone()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_DeleteGap()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GAP_STANDBY()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GapType_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_SetGap_TD()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_Ignore_gaps()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_BSICSchedule_TD()	ChkL1ClsFltr_L1DM_DMBSIC_M()
#define ChkL1MsgFltr_L1DM_MSG_PMLock_TD()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_PMPeriod()	ChkL1ClsFltr_L1DM_DMPM_M()
#define ChkL1MsgFltr_L1DM_MSG_ReselMode_Standby()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGapStart()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGapEnd()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_2GAutoGAPTimer()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPGet()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPPut()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPConfirm()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GSMAutoGAPStop()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_GetGSMAutoGAPLength()	ChkL1ClsFltr_L1DM_DMGAP_M()
#define ChkL1MsgFltr_L1DM_MSG_LTE_Connecedt_GAP()	ChkL1ClsFltr_L1DM_DMGAP_M()


#endif
