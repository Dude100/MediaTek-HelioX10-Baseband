#ifndef L1TRC_EPDCP_DETAIL_DEF_H
#define L1TRC_EPDCP_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0010 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0110 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0210 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0310 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0410 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0510 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SCALE_LPBK_SDU(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0610 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SCALE_LPBK_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0710 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0810 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0910 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_EMPTY_DL_WINDOW(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A10 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_EMPTY_DL_WINDOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(v1) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B10 | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(v1, v2) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C10 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_DTL_LOG_UNEXP_PC_STOP(v1, v2, v3) do {\
		if(EPDCP_DETAIL_Trace_Filter[0]==1 && (EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0D10 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_DTL_LOG_UNEXP_PC_STOP(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EPDCP_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_HWM(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_SWM(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_SCALE_LPBK_SDU(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_EMPTY_DL_WINDOW(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND(short v1);
void L1TRC_Send_EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND(short v1, long v2);
void L1TRC_Send_EPDCP_DTL_LOG_UNEXP_PC_STOP(short v1, long v2, long v3);

void Set_EPDCP_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EPDCP_DETAIL()	(EPDCP_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()	(ChkL1ModFltr_EPDCP_DETAIL()&&((EPDCP_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_CB_PDU_TO_CB_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_CB_PDU_TO_OK_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RX_OK_PDU_TO_OK_QUE()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_HWM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_SWM()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_OOW_PDU_INFO_ROHC()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SCALE_LPBK_SDU()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_NO_SCALE_LPBK_SDU()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_PACKET()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_DCCH_DATA_RES_PARAM_WRONG()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_RESUME_CHNL_WO_VALID_DRB()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_EMPTY_DL_WINDOW()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_DBG()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_MERGE_DL_PDUS_TO_REORD_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_SEARCH_CONTINUE_PC_FROM_WND()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()
#define ChkL1MsgFltr_EPDCP_DTL_LOG_UNEXP_PC_STOP()	ChkL1ClsFltr_EPDCP_DETAIL_EPDCP_BRANCH()


#endif
