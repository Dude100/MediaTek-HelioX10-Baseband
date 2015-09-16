#ifndef L1TRC_UL1SM_1_DEF_H
#define L1TRC_UL1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1SM_Trc_Str_Bool(v1)  (unsigned char)(v1+0)
#define UL1SM_Str_Sleep_FRC(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CALI_START() do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CALI_START()
#endif
#define UL1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CALI_DONE(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x013D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_CALI_DONE(v1, v2, v3)
#endif
#define UL1SM_DBG_CALI_DONE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x013D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_LONG_CALI_DONE(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x023D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_LONG_CALI_DONE(v1, v2, v3)
#endif
#define UL1SM_DBG_LONG_CALI_DONE_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x023D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_TOPSM_PASS_3G(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x033D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1SM_DBG_TOPSM_PASS_3G(v1, v2)
#endif
#define UL1SM_DBG_TOPSM_PASS_3G_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x033D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_SW_WAKEUP(v1) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_SW_WAKEUP(v1)
#endif
#define UL1SM_DBG_SW_WAKEUP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x043D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CAL_SLEEP(v1, v2, v3, v4) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x053D, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1SM_DBG_CAL_SLEEP(v1, v2, v3, v4)
#endif
#define UL1SM_DBG_CAL_SLEEP_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x053D, (unsigned short)(v3)), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_CAL_HW_SLEEP(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CAL_HW_SLEEP(v1, v2)
#endif
#define UL1SM_DBG_CAL_HW_SLEEP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x063D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1SM_DBG_CHECK_SLEEP_F(v1, v2, v3, v4) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x073D, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_SLEEP_F(v1, v2, v3, v4)
#endif
#define UL1SM_DBG_CHECK_SLEEP_F_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x073D, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x083D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_CHECK_SLEEP_C(v1, v2, v3, v4, v5)
#endif
#define UL1SM_DBG_CHECK_SLEEP_C_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x083D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), TRC_MERGE_1S2C((unsigned short)(v5), (unsigned char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_BEFORE_SLEEP(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x093D, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_DBG_BEFORE_SLEEP(v1, v2, v3)
#endif
#define UL1SM_DBG_BEFORE_SLEEP_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x093D, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3D, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define UL1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define UL1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A3D, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B3D, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif
#define UL1SM_TRC_DEBUG_HEX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0B3D, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1SM_DBG_SLEEP_FRC(v1, v2, v3, v4) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C3D, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1SM_DBG_SLEEP_FRC(v1, v2, v3, v4)
#endif
#define UL1SM_DBG_SLEEP_FRC_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0C3D, (unsigned char)(v1), (unsigned char)(v3)), (unsigned long)(v2), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1SM_DBG_32KLESS_WAKEUP(v1, v2) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_32KLESS_WAKEUP(v1, v2)
#endif
#define UL1SM_DBG_32KLESS_WAKEUP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0D3D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5) do {\
		if(UL1SM_1_Trace_Filter[0]==1 && (UL1SM_1_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1SM_DBG_32KLESS_UPDATE_LPM(v1, v2, v3, v4, v5)
#endif
#define UL1SM_DBG_32KLESS_UPDATE_LPM_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0E3D, (short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v5), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1SM_DBG_CALI_START(void);
void L1TRC_Send_UL1SM_DBG_CALI_DONE(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_DBG_LONG_CALI_DONE(unsigned char v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_DBG_TOPSM_PASS_3G(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1SM_DBG_SW_WAKEUP(unsigned char v1);
void L1TRC_Send_UL1SM_DBG_CAL_SLEEP(unsigned long v1, unsigned long v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_UL1SM_DBG_CAL_HW_SLEEP(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1SM_DBG_CHECK_SLEEP_F(unsigned long v1, unsigned short v2, unsigned char v3, unsigned short v4);
void L1TRC_Send_UL1SM_DBG_CHECK_SLEEP_C(unsigned short v1, unsigned char v2, unsigned short v3, unsigned short v4, unsigned short v5);
void L1TRC_Send_UL1SM_DBG_BEFORE_SLEEP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_UL1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1SM_DBG_SLEEP_FRC(unsigned char v1, unsigned long v2, unsigned char v3, unsigned long v4);
void L1TRC_Send_UL1SM_DBG_32KLESS_WAKEUP(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1SM_DBG_32KLESS_UPDATE_LPM(short v1, unsigned short v2, unsigned short v3, unsigned short v4, unsigned char v5);

void Set_UL1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1SM_1()	(UL1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1SM_1_UMTS_SM_L()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()	(ChkL1ModFltr_UL1SM_1()&&((UL1SM_1_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_UL1SM_DBG_CALI_START()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CALI_DONE()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_LONG_CALI_DONE()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_TOPSM_PASS_3G()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_SW_WAKEUP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CAL_SLEEP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CAL_HW_SLEEP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_SLEEP_F()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_L()
#define ChkL1MsgFltr_UL1SM_DBG_CHECK_SLEEP_C()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_L()
#define ChkL1MsgFltr_UL1SM_DBG_BEFORE_SLEEP()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_TRC_DEBUG()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_SLEEP_FRC()	ChkL1ClsFltr_UL1SM_1_UMTS_SM_M()
#define ChkL1MsgFltr_UL1SM_DBG_32KLESS_WAKEUP()	ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()
#define ChkL1MsgFltr_UL1SM_DBG_32KLESS_UPDATE_LPM()	ChkL1ClsFltr_UL1SM_1_UMTS_32K_H()


#endif
