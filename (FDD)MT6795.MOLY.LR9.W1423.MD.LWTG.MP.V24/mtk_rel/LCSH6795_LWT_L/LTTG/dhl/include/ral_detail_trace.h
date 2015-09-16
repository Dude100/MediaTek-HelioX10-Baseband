#ifndef L1TRC_RAL_DETAIL_DEF_H
#define L1TRC_RAL_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_TRG_INT(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0019 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_TRG_INT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_UL_POLL(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0119 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_UL_POLL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_DL_POLL(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0219 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_DL_POLL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_FDBK_POLL(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0319 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_FDBK_POLL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_UL_NO_PKT(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0419 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_UL_NO_PKT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_UL_CMPRS_ENTER(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0519 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_UL_CMPRS_ENTER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_UL_CMPRS_LEAVE(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0619 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_UL_CMPRS_LEAVE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_DL_NO_PKT(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0719 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_DL_NO_PKT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_DL_DECMPRS_ENTER(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0819 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_DL_DECMPRS_ENTER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_UL_DECMPRS_LEAVE(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0919 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_UL_DECMPRS_LEAVE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_ROHC_PROC_START(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A19 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_ROHC_PROC_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_ROHC_PROC_STOP(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0B19 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_ROHC_PROC_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_CR4_CTRL_INFO_ADDR(v1, v2) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0C19 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_CR4_CTRL_INFO_ADDR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_ROHC_ISR(v1) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0D19 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_ROHC_ISR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_DL_EPDCP_CNT_2_IPID(v1, v2, v3) do {\
		if(RAL_DETAIL_Trace_Filter[0]==1 && (RAL_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0E19 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RAL_LOG_DL_EPDCP_CNT_2_IPID(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char RAL_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RAL_LOG_CR4_TRG_INT(short v1);
void L1TRC_Send_RAL_LOG_CR4_UL_POLL(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_DL_POLL(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_FDBK_POLL(short v1);
void L1TRC_Send_RAL_LOG_MCU_UL_NO_PKT(short v1);
void L1TRC_Send_RAL_LOG_MCU_UL_CMPRS_ENTER(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_UL_CMPRS_LEAVE(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_DL_NO_PKT(short v1);
void L1TRC_Send_RAL_LOG_MCU_DL_DECMPRS_ENTER(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_UL_DECMPRS_LEAVE(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_ROHC_PROC_START(short v1);
void L1TRC_Send_RAL_LOG_MCU_ROHC_PROC_STOP(short v1);
void L1TRC_Send_RAL_LOG_MCU_CR4_CTRL_INFO_ADDR(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_ROHC_ISR(short v1);
void L1TRC_Send_RAL_LOG_DL_EPDCP_CNT_2_IPID(short v1, unsigned long v2, unsigned long v3);

void Set_RAL_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_RAL_DETAIL()	(RAL_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_RAL_DETAIL_RAL_FUNC()	(ChkL1ModFltr_RAL_DETAIL()&&((RAL_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_RAL_DETAIL_RAL_BRANCH()	(ChkL1ModFltr_RAL_DETAIL()&&((RAL_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()	(ChkL1ModFltr_RAL_DETAIL()&&((RAL_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_RAL_LOG_CR4_TRG_INT()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_CR4_UL_POLL()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_CR4_DL_POLL()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_CR4_FDBK_POLL()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_UL_NO_PKT()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_UL_CMPRS_ENTER()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_UL_CMPRS_LEAVE()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_DL_NO_PKT()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_DL_DECMPRS_ENTER()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_UL_DECMPRS_LEAVE()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_ROHC_PROC_START()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_ROHC_PROC_STOP()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_CR4_CTRL_INFO_ADDR()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_MCU_ROHC_ISR()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()
#define ChkL1MsgFltr_RAL_LOG_DL_EPDCP_CNT_2_IPID()	ChkL1ClsFltr_RAL_DETAIL_RAL_PACKET()


#endif
