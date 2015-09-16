#ifndef L1TRC_QMU_BM_DEF_H
#define L1TRC_QMU_BM_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_InitByCfg1(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0015 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_InitByCfg1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_InitByCfg2(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0115 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_InitByCfg2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_AllocQueueStr(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0215 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_AllocQueueStr(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_AllocQueueEnd(v1, v2, v3, v4, v5) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0x0315 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define TrcQBM_AllocQueueEnd(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_AllocOne(v1, v2, v3) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0415 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define TrcQBM_AllocOne(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_FreeQueue(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0515 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_FreeQueue(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_FreeOne(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_2_word(0x0615 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_FreeOne(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_FreeQ_Str(v1, v2, v3) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x0715 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define TrcQBM_FreeQ_Str(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_FreeQ_End(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x0815 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_FreeQ_End(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_AllocFromFLC(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_2_word(0x0915 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TrcQBM_AllocFromFLC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_Rel2FLCStr(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_2_word(0x0A15 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_Rel2FLCStr(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_Rel2FLCEnd(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_2_word(0x0B15 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_Rel2FLCEnd(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_ReloadFromFLC(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x40)!=0 )\
			l2trc_send_4_word(0x0C15 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define TrcQBM_ReloadFromFLC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_EnQCommon(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[1]&0x80)!=0 )\
			l2trc_send_4_word(0x0D15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_EnQCommon(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_EnQWthBypass(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x01)!=0 )\
			l2trc_send_4_word(0x0E15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_EnQWthBypass(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_EnQCommonRx(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x02)!=0 )\
			l2trc_send_4_word(0x0F15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_EnQCommonRx(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_DeQ(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_2_word(0x1015 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_DeQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_DeQTx(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x08)!=0 )\
			l2trc_send_4_word(0x1115 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_DeQTx(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_DeQHIF_UL_Str(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x08)!=0 )\
			l2trc_send_4_word(0x1215 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TrcQBM_DeQHIF_UL_Str(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_DeQHIF_UL_End(v1, v2, v3, v4, v5) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x04)!=0 )\
			l2trc_send_5_word(0x1315 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define TrcQBM_DeQHIF_UL_End(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_SetExtParam(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x10)!=0 )\
			l2trc_send_2_word(0x1415 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_SetExtParam(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_GetRemain(v1, v2) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x10)!=0 )\
			l2trc_send_2_word(0x1515 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TrcQBM_GetRemain(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_GetRemainFLC_Chk(v1, v2, v3) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x20)!=0 )\
			l2trc_send_3_word(0x1615 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TrcQBM_GetRemainFLC_Chk(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TrcQBM_PoolStatus(v1, v2, v3, v4) do {\
		if(QMU_BM_Trace_Filter[0]==1 && (QMU_BM_Trace_Filter[2]&0x10)!=0 )\
			l2trc_send_3_word(0x1715 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)((char)(v4))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define TrcQBM_PoolStatus(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char QMU_BM_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_TrcQBM_InitByCfg1(short v1, char v2, char v3, char v4);
void L1TRC_Send_TrcQBM_InitByCfg2(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_AllocQueueStr(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_AllocQueueEnd(unsigned short v1, unsigned long v2, char v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_TrcQBM_AllocOne(short v1, char v2, unsigned long v3);
void L1TRC_Send_TrcQBM_FreeQueue(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_FreeOne(short v1, char v2);
void L1TRC_Send_TrcQBM_FreeQ_Str(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_TrcQBM_FreeQ_End(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_AllocFromFLC(short v1, long v2);
void L1TRC_Send_TrcQBM_Rel2FLCStr(short v1, char v2);
void L1TRC_Send_TrcQBM_Rel2FLCEnd(short v1, char v2);
void L1TRC_Send_TrcQBM_ReloadFromFLC(short v1, char v2, long v3, long v4);
void L1TRC_Send_TrcQBM_EnQCommon(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_EnQWthBypass(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_EnQCommonRx(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_DeQ(short v1, char v2);
void L1TRC_Send_TrcQBM_DeQTx(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_DeQHIF_UL_Str(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TrcQBM_DeQHIF_UL_End(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_TrcQBM_SetExtParam(short v1, char v2);
void L1TRC_Send_TrcQBM_GetRemain(short v1, char v2);
void L1TRC_Send_TrcQBM_GetRemainFLC_Chk(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TrcQBM_PoolStatus(short v1, unsigned long v2, char v3, char v4);

void Set_QMU_BM_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_QMU_BM()	(QMU_BM_Trace_Filter[0]==1)
#define ChkL1ClsFltr_QMU_BM_AllocBuff()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_QMU_BM_AllocBuffDetail()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_QMU_BM_AllocBuffDetailDFT()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_QMU_BM_FreeBuff()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_QMU_BM_FreeBuffDetail()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_QMU_BM_FreeBuffDetailDFT()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_QMU_BM_FLC()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_QMU_BM_EnQueue()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_QMU_BM_EnQueueDetail()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_QMU_BM_EnQueueDetailDFT()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_QMU_BM_DeQueue()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_QMU_BM_DeQueueDetail()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_QMU_BM_Others()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x10)!=0))
#define ChkL1ClsFltr_QMU_BM_OthersDetail()	(ChkL1ModFltr_QMU_BM()&&((QMU_BM_Trace_Filter[2]&0x20)!=0))
#define ChkL1MsgFltr_TrcQBM_InitByCfg1()	ChkL1ClsFltr_QMU_BM_AllocBuff()
#define ChkL1MsgFltr_TrcQBM_InitByCfg2()	ChkL1ClsFltr_QMU_BM_AllocBuff()
#define ChkL1MsgFltr_TrcQBM_AllocQueueStr()	ChkL1ClsFltr_QMU_BM_AllocBuffDetail()
#define ChkL1MsgFltr_TrcQBM_AllocQueueEnd()	ChkL1ClsFltr_QMU_BM_AllocBuff()
#define ChkL1MsgFltr_TrcQBM_AllocOne()	ChkL1ClsFltr_QMU_BM_AllocBuffDetailDFT()
#define ChkL1MsgFltr_TrcQBM_FreeQueue()	ChkL1ClsFltr_QMU_BM_FreeBuff()
#define ChkL1MsgFltr_TrcQBM_FreeOne()	ChkL1ClsFltr_QMU_BM_FreeBuffDetailDFT()
#define ChkL1MsgFltr_TrcQBM_FreeQ_Str()	ChkL1ClsFltr_QMU_BM_FreeBuffDetail()
#define ChkL1MsgFltr_TrcQBM_FreeQ_End()	ChkL1ClsFltr_QMU_BM_FreeBuffDetail()
#define ChkL1MsgFltr_TrcQBM_AllocFromFLC()	ChkL1ClsFltr_QMU_BM_FLC()
#define ChkL1MsgFltr_TrcQBM_Rel2FLCStr()	ChkL1ClsFltr_QMU_BM_FLC()
#define ChkL1MsgFltr_TrcQBM_Rel2FLCEnd()	ChkL1ClsFltr_QMU_BM_FLC()
#define ChkL1MsgFltr_TrcQBM_ReloadFromFLC()	ChkL1ClsFltr_QMU_BM_FLC()
#define ChkL1MsgFltr_TrcQBM_EnQCommon()	ChkL1ClsFltr_QMU_BM_EnQueue()
#define ChkL1MsgFltr_TrcQBM_EnQWthBypass()	ChkL1ClsFltr_QMU_BM_EnQueueDetail()
#define ChkL1MsgFltr_TrcQBM_EnQCommonRx()	ChkL1ClsFltr_QMU_BM_EnQueueDetailDFT()
#define ChkL1MsgFltr_TrcQBM_DeQ()	ChkL1ClsFltr_QMU_BM_DeQueue()
#define ChkL1MsgFltr_TrcQBM_DeQTx()	ChkL1ClsFltr_QMU_BM_DeQueueDetail()
#define ChkL1MsgFltr_TrcQBM_DeQHIF_UL_Str()	ChkL1ClsFltr_QMU_BM_DeQueueDetail()
#define ChkL1MsgFltr_TrcQBM_DeQHIF_UL_End()	ChkL1ClsFltr_QMU_BM_DeQueue()
#define ChkL1MsgFltr_TrcQBM_SetExtParam()	ChkL1ClsFltr_QMU_BM_Others()
#define ChkL1MsgFltr_TrcQBM_GetRemain()	ChkL1ClsFltr_QMU_BM_Others()
#define ChkL1MsgFltr_TrcQBM_GetRemainFLC_Chk()	ChkL1ClsFltr_QMU_BM_OthersDetail()
#define ChkL1MsgFltr_TrcQBM_PoolStatus()	ChkL1ClsFltr_QMU_BM_Others()


#endif
