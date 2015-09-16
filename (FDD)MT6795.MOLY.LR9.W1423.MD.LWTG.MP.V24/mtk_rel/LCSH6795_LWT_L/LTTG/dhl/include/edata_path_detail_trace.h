#ifndef L1TRC_EDATA_PATH_DETAIL_DEF_H
#define L1TRC_EDATA_PATH_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_ERT_HISR_IN(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0012 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define ILM_ERT_HISR_IN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_ERT_HISR_DSP_TIMER(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0112 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ILM_ERT_HISR_DSP_TIMER(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0212 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ILM_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ILM_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0312 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ILM_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0412 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ERT_ILM_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERT_ILM_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0512 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ERT_ILM_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_IN(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0612 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_IN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define POLL_CYCLES(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0712 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define POLL_CYCLES(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_HISR_OUT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0812 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_HISR_OUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define PROTECT(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0912 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define PROTECT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_EPSB_DL_CYCLES(v1, v2, v3) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_3_word(0x0A12 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define LTM_PROCESS_EPSB_DL_CYCLES(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_UL_SDU(v1, v2, v3, v4) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0B12 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define LTM_PROCESS_UL_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_RCV_UL(v1, v2) do {\
		if(EDATA_PATH_DETAIL_Trace_Filter[0]==1 && (EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0C12 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_RCV_UL(v1, v2)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EDATA_PATH_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ILM_ERT_HISR_IN(unsigned short v1, unsigned long v2, short v3, unsigned long v4);
void L1TRC_Send_ILM_ERT_HISR_DSP_TIMER(unsigned short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_ILM_IN(unsigned short v1, short v2, unsigned long v3);
void L1TRC_Send_ILM_OUT(unsigned short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ERT_ILM_IN(unsigned short v1, short v2, unsigned long v3);
void L1TRC_Send_ERT_ILM_OUT(unsigned short v1, short v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_IN(short v1, char v2, unsigned long v3);
void L1TRC_Send_POLL_CYCLES(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_ENTER_DSP_TIMER_HISR_OUT(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_PROTECT(short v1, char v2, char v3);
void L1TRC_Send_LTM_PROCESS_EPSB_DL_CYCLES(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_LTM_PROCESS_UL_SDU(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_LTM_RCV_UL(short v1, char v2);

void Set_EDATA_PATH_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EDATA_PATH_DETAIL()	(EDATA_PATH_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()	(ChkL1ModFltr_EDATA_PATH_DETAIL()&&((EDATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_ILM_ERT_HISR_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_ERT_HISR_DSP_TIMER()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ILM_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ERT_ILM_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ERT_ILM_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_IN()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_POLL_CYCLES()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_HISR_OUT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_PROTECT()	ChkL1ClsFltr_EDATA_PATH_DETAIL_EDYN_DFT()
#define ChkL1MsgFltr_LTM_PROCESS_EPSB_DL_CYCLES()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()
#define ChkL1MsgFltr_LTM_PROCESS_UL_SDU()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()
#define ChkL1MsgFltr_LTM_RCV_UL()	ChkL1ClsFltr_EDATA_PATH_DETAIL_LTM_DFT()


#endif
