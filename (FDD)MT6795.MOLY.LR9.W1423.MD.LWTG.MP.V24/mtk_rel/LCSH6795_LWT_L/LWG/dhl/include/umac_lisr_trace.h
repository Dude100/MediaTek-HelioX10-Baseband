#ifndef L1TRC_UMAC_DEF_H
#define L1TRC_UMAC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UMAC_TRC_UPARAW(v1, v2, v3, v4) do {\
		if(UMAC_Trace_Filter[0]==1 && (UMAC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UMAC_TRC_UPARAW(v1, v2, v3, v4)
#endif
#define UMAC_TRC_UPARAW_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x003F, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UMAC_HSDSCH_BLOCK_GET_INFO_A(v1) do {\
		if(UMAC_Trace_Filter[0]==1 && (UMAC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x013F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UMAC_HSDSCH_BLOCK_GET_INFO_A(v1)
#endif
#define UMAC_HSDSCH_BLOCK_GET_INFO_A_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x013F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UMAC_HSDSCH_BLOCK_GET_INFO_B(v1) do {\
		if(UMAC_Trace_Filter[0]==1 && (UMAC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x023F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UMAC_HSDSCH_BLOCK_GET_INFO_B(v1)
#endif
#define UMAC_HSDSCH_BLOCK_GET_INFO_B_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x023F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UMAC_HSDSCH_BLOCK_FREE_INFO_B(v1) do {\
		if(UMAC_Trace_Filter[0]==1 && (UMAC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UMAC_HSDSCH_BLOCK_FREE_INFO_B(v1)
#endif
#define UMAC_HSDSCH_BLOCK_FREE_INFO_B_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x033F, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UMAC_HSDSCH_BLOCK_FREE_NUM_B(v1, v2) do {\
		if(UMAC_Trace_Filter[0]==1 && (UMAC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x043F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UMAC_HSDSCH_BLOCK_FREE_NUM_B(v1, v2)
#endif
#define UMAC_HSDSCH_BLOCK_FREE_NUM_B_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x043F, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UMAC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UMAC_TRC_UPARAW(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UMAC_HSDSCH_BLOCK_GET_INFO_A(unsigned long v1);
void L1TRC_Send_UMAC_HSDSCH_BLOCK_GET_INFO_B(unsigned long v1);
void L1TRC_Send_UMAC_HSDSCH_BLOCK_FREE_INFO_B(unsigned long v1);
void L1TRC_Send_UMAC_HSDSCH_BLOCK_FREE_NUM_B(unsigned short v1, unsigned short v2);

void Set_UMAC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UMAC()	(UMAC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UMAC_UMAC_UPARAW_M()	(ChkL1ModFltr_UMAC()&&((UMAC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UMAC_UMAC_HSPDU_BUFF_TRACE_M()	(ChkL1ModFltr_UMAC()&&((UMAC_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_UMAC_TRC_UPARAW()	ChkL1ClsFltr_UMAC_UMAC_UPARAW_M()
#define ChkL1MsgFltr_UMAC_HSDSCH_BLOCK_GET_INFO_A()	ChkL1ClsFltr_UMAC_UMAC_HSPDU_BUFF_TRACE_M()
#define ChkL1MsgFltr_UMAC_HSDSCH_BLOCK_GET_INFO_B()	ChkL1ClsFltr_UMAC_UMAC_HSPDU_BUFF_TRACE_M()
#define ChkL1MsgFltr_UMAC_HSDSCH_BLOCK_FREE_INFO_B()	ChkL1ClsFltr_UMAC_UMAC_HSPDU_BUFF_TRACE_M()
#define ChkL1MsgFltr_UMAC_HSDSCH_BLOCK_FREE_NUM_B()	ChkL1ClsFltr_UMAC_UMAC_HSPDU_BUFF_TRACE_M()


#endif
