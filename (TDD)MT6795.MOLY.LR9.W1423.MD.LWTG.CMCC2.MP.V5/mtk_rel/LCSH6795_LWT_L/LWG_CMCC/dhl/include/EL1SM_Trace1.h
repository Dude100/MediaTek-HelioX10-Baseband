#ifndef L1TRC_EL1SM_1_DEF_H
#define L1TRC_EL1SM_1_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EL1SM_Str_Locker(v1)  (unsigned char)(v1+0)
#define EL1SM_Str_Bool(v1)  (unsigned char)(v1+8)
#define EL1SM_Str_Enable(v1)  (unsigned char)(v1+10)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_SM_LOCKER(v1, v2, v3, v4) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x004E, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_SM_LOCKER(v1, v2, v3, v4)
#endif
#define EL1SM_DBG_CHECK_SM_LOCKER_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x004E, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Enter_Sleep(v1, v2, v3, v4, v5) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x014E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define EL1SM_DBG_Enter_Sleep(v1, v2, v3, v4, v5)
#endif
#define EL1SM_DBG_Enter_Sleep_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_6_DATA(TRC_MERGE_1S2C(0x014E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_SW_Wakeup(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x024E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_SW_Wakeup(v1, v2)
#endif
#define EL1SM_DBG_SW_Wakeup_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x024E, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_Wakeup_IRQ(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x034E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_Wakeup_IRQ(v1, v2)
#endif
#define EL1SM_DBG_Wakeup_IRQ_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x034E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CALI_START() do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x044E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EL1SM_DBG_CALI_START()
#endif
#define EL1SM_DBG_CALI_START_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x044E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CALI_DONE(v1, v2) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x054E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_CALI_DONE(v1, v2)
#endif
#define EL1SM_DBG_CALI_DONE_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x054E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_DBG_CHECK_SLEEP(v1, v2, v3, v4, v5) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x064E, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define EL1SM_DBG_CHECK_SLEEP(v1, v2, v3, v4, v5)
#endif
#define EL1SM_DBG_CHECK_SLEEP_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x064E, (unsigned char)(v3), (unsigned char)(v4)), TRC_MERGE_4C((unsigned char)(v5), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define EL1SM_TRC_DEBUG(v1, v2, v3) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x074E, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EL1SM_TRC_DEBUG(v1, v2, v3)
#endif
#define EL1SM_TRC_DEBUG_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x074E, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EL1SM_TRC_DEBUG_HEX(v1, v2, v3) do {\
		if(EL1SM_1_Trace_Filter[0]==1 && (EL1SM_1_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x084E, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EL1SM_TRC_DEBUG_HEX(v1, v2, v3)
#endif
#define EL1SM_TRC_DEBUG_HEX_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x084E, (unsigned short)(v1)), (unsigned long)(v2), (unsigned long)(v3))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1SM_1_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EL1SM_DBG_CHECK_SM_LOCKER(unsigned char v1, unsigned char v2, unsigned short v3, unsigned long v4);
void L1TRC_Send_EL1SM_DBG_Enter_Sleep(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_EL1SM_DBG_SW_Wakeup(unsigned char v1, unsigned long v2);
void L1TRC_Send_EL1SM_DBG_Wakeup_IRQ(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1SM_DBG_CALI_START(void);
void L1TRC_Send_EL1SM_DBG_CALI_DONE(unsigned long v1, unsigned long v2);
void L1TRC_Send_EL1SM_DBG_CHECK_SLEEP(unsigned long v1, unsigned long v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EL1SM_TRC_DEBUG(unsigned short v1, long v2, long v3);
void L1TRC_Send_EL1SM_TRC_DEBUG_HEX(unsigned short v1, unsigned long v2, unsigned long v3);

void Set_EL1SM_1_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1SM_1()	(EL1SM_1_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1SM_1_LTE_SM_H()	(ChkL1ModFltr_EL1SM_1()&&((EL1SM_1_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1SM_1_LTE_SM_L()	(ChkL1ModFltr_EL1SM_1()&&((EL1SM_1_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_SM_LOCKER()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Enter_Sleep()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_SW_Wakeup()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_Wakeup_IRQ()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CALI_START()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CALI_DONE()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_DBG_CHECK_SLEEP()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_TRC_DEBUG()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()
#define ChkL1MsgFltr_EL1SM_TRC_DEBUG_HEX()	ChkL1ClsFltr_EL1SM_1_LTE_SM_H()


#endif
