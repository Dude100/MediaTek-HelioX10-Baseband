#ifndef L1TRC_RAL_DEF_H
#define L1TRC_RAL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_GENERIC(v1, v2, v3, v4) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0018 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define RAL_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_SND_CMD_START(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0118 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_SND_CMD_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_SND_CMD_END(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0218 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_SND_CMD_END(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_QUE_FULL(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0318 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_QUE_FULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_QUE_FULL_1(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0418 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_QUE_FULL_1(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_QUE_FULL_2(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0518 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_QUE_FULL_2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_INIT_CMD_START(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0618 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_INIT_CMD_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_INIT_CMD_END(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0718 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_INIT_CMD_END(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_RAL_MCU_NOT_INIT(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0818 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_RAL_MCU_NOT_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_POLL_START(v1, v2, v3) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0918 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_POLL_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_POLL_END(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0A18 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_POLL_END(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_RTP_SN_CONFIDENCE(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_RTP_SN_CONFIDENCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_RTP_TS_CONFIDENCE(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0C18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_RTP_TS_CONFIDENCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_RBM_USG(v1, v2, v3) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0D18 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define RAL_LOG_MCU_RBM_USG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_START(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0E18 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_END(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0F18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_INIT(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1018 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_ADD_INST(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1118 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_ADD_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_DEL_INST(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1218 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_DEL_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_RST_INST(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1318 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_RST_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_RST_INST_PARAM(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1418 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_RST_INST_PARAM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_EXE_CMD_UL_END(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1518 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_EXE_CMD_UL_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_DL_POLL_PKT_DROP(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1618 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_DL_POLL_PKT_DROP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CAIF_MSG_BUF_READ_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1718 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_CAIF_MSG_BUF_READ_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_FDBK_GPD_ALLOC_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1818 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_FDBK_GPD_ALLOC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_UL_GPD_ALLOC_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1918 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_UL_GPD_ALLOC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMPRS_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1A18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMPRS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_RBM_BUF_TYPE_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1B18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_RBM_BUF_TYPE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_CMPRS_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1C18 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_CMPRS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_RES_ERR(v1, v2, v3) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1D18 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_RES_ERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_INST_PARAM_ERR(v1, v2, v3) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1E18 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_INST_PARAM_ERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_CR4_CMD_ID_ERR(v1, v2) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1F18 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RAL_LOG_CR4_CMD_ID_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RAL_LOG_MCU_RBM_ALLOW_LEN_ERR(v1) do {\
		if(RAL_Trace_Filter[0]==1 && (RAL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2018 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RAL_LOG_MCU_RBM_ALLOW_LEN_ERR(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char RAL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RAL_LOG_GENERIC(short v1, long v2, long v3, long v4);
void L1TRC_Send_RAL_LOG_CR4_SND_CMD_START(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_SND_CMD_END(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_CMD_QUE_FULL(short v1);
void L1TRC_Send_RAL_LOG_CR4_CMD_QUE_FULL_1(short v1);
void L1TRC_Send_RAL_LOG_CR4_CMD_QUE_FULL_2(short v1);
void L1TRC_Send_RAL_LOG_CR4_INIT_CMD_START(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_INIT_CMD_END(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_RAL_MCU_NOT_INIT(short v1);
void L1TRC_Send_RAL_LOG_CR4_CMD_POLL_START(short v1, long v2, long v3);
void L1TRC_Send_RAL_LOG_CR4_CMD_POLL_END(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_RTP_SN_CONFIDENCE(short v1);
void L1TRC_Send_RAL_LOG_CR4_RTP_TS_CONFIDENCE(short v1);
void L1TRC_Send_RAL_LOG_MCU_RBM_USG(short v1, long v2, long v3);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_START(short v1, long v2);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_END(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_INIT(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_ADD_INST(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_DEL_INST(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_RST_INST(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_RST_INST_PARAM(short v1);
void L1TRC_Send_RAL_LOG_MCU_EXE_CMD_UL_END(short v1);
void L1TRC_Send_RAL_LOG_CR4_DL_POLL_PKT_DROP(short v1, long v2);
void L1TRC_Send_RAL_LOG_CR4_CAIF_MSG_BUF_READ_ERR(short v1);
void L1TRC_Send_RAL_LOG_CR4_FDBK_GPD_ALLOC_ERR(short v1);
void L1TRC_Send_RAL_LOG_CR4_UL_GPD_ALLOC_ERR(short v1);
void L1TRC_Send_RAL_LOG_CR4_CMPRS_ERR(short v1);
void L1TRC_Send_RAL_LOG_MCU_RBM_BUF_TYPE_ERR(short v1);
void L1TRC_Send_RAL_LOG_MCU_CMPRS_ERR(short v1);
void L1TRC_Send_RAL_LOG_CR4_CMD_RES_ERR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RAL_LOG_CR4_CMD_INST_PARAM_ERR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RAL_LOG_CR4_CMD_ID_ERR(short v1, unsigned long v2);
void L1TRC_Send_RAL_LOG_MCU_RBM_ALLOW_LEN_ERR(short v1);

void Set_RAL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_RAL()	(RAL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_RAL_RAL_INFO()	(ChkL1ModFltr_RAL()&&((RAL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_RAL_RAL_DUMP()	(ChkL1ModFltr_RAL()&&((RAL_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_RAL_LOG_GENERIC()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_SND_CMD_START()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_SND_CMD_END()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_QUE_FULL()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_QUE_FULL_1()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_QUE_FULL_2()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_INIT_CMD_START()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_INIT_CMD_END()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_RAL_MCU_NOT_INIT()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_POLL_START()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_POLL_END()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_CR4_RTP_SN_CONFIDENCE()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_RTP_TS_CONFIDENCE()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_RBM_USG()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_START()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_END()	ChkL1ClsFltr_RAL_RAL_DUMP()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_INIT()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_ADD_INST()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_DEL_INST()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_RST_INST()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_RST_INST_PARAM()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_EXE_CMD_UL_END()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_DL_POLL_PKT_DROP()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CAIF_MSG_BUF_READ_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_FDBK_GPD_ALLOC_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_UL_GPD_ALLOC_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMPRS_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_RBM_BUF_TYPE_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_CMPRS_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_RES_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_INST_PARAM_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_CR4_CMD_ID_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()
#define ChkL1MsgFltr_RAL_LOG_MCU_RBM_ALLOW_LEN_ERR()	ChkL1ClsFltr_RAL_RAL_INFO()


#endif
