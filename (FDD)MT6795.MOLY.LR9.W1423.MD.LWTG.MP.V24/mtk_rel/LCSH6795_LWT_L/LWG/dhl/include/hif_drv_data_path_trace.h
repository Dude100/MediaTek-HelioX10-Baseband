#ifndef L1TRC_HIF_DRV_DEF_H
#define L1TRC_HIF_DRV_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define HIF_DRV_DUMMY(v1) do {\
		if(HIF_DRV_Trace_Filter[0]==1 && (HIF_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x001C | ((short)(v1) << 16));\
	} while(0)
#else
	#define HIF_DRV_DUMMY(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char HIF_DRV_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_HIF_DRV_DUMMY(short v1);

void Set_HIF_DRV_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_HIF_DRV()	(HIF_DRV_Trace_Filter[0]==1)
#define ChkL1ClsFltr_HIF_DRV_UL()	(ChkL1ModFltr_HIF_DRV()&&((HIF_DRV_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_HIF_DRV_DL()	(ChkL1ModFltr_HIF_DRV()&&((HIF_DRV_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_HIF_DRV_DUMMY()	ChkL1ClsFltr_HIF_DRV_UL()


#endif
