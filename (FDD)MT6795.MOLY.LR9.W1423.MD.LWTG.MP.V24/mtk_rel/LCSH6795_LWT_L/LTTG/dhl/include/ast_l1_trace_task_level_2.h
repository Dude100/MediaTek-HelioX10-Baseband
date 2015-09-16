#ifndef L1TRC_AST_L1_Trace_Task_Context_Group2_DEF_H
#define L1TRC_AST_L1_Trace_Task_Context_Group2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define Str_Bool(v1)  (unsigned char)(v1+0)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_1(v1) do {\
		if(AST_L1_Trace_Task_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0040, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_1(v1)
#endif
#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_1_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0040, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_2(v1) do {\
		if(AST_L1_Trace_Task_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0140, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_2(v1)
#endif
#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_2_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0140, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_3(v1) do {\
		if(AST_L1_Trace_Task_Context_Group2_Trace_Filter[0]==1 && (AST_L1_Trace_Task_Context_Group2_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0240, (unsigned short)(v1)));\
	} while(0)
#else
	#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_3(v1)
#endif
#define AST_L1_Trace_Task_Context_Group2_TEST_MSG_3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0240, (unsigned short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char AST_L1_Trace_Task_Context_Group2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_AST_L1_Trace_Task_Context_Group2_TEST_MSG_1(unsigned char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group2_TEST_MSG_2(char v1);
void L1TRC_Send_AST_L1_Trace_Task_Context_Group2_TEST_MSG_3(unsigned short v1);

void Set_AST_L1_Trace_Task_Context_Group2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_AST_L1_Trace_Task_Context_Group2()	(AST_L1_Trace_Task_Context_Group2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group2_TEST_CLASS_1()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group2()&&((AST_L1_Trace_Task_Context_Group2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group2_TEST_CLASS_2()	(ChkL1ModFltr_AST_L1_Trace_Task_Context_Group2()&&((AST_L1_Trace_Task_Context_Group2_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group2_TEST_MSG_1()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group2_TEST_CLASS_1()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group2_TEST_MSG_2()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group2_TEST_CLASS_2()
#define ChkL1MsgFltr_AST_L1_Trace_Task_Context_Group2_TEST_MSG_3()	ChkL1ClsFltr_AST_L1_Trace_Task_Context_Group2_TEST_CLASS_1()


#endif
