#ifndef L1TRC_NAS_DATA_PATH_DETAIL_DEF_H
#define L1TRC_NAS_DATA_PATH_DETAIL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_RcvULDummy(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0014 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RATADP_RcvULDummy(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_ToRatdm(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0114 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define RATADP_ToRatdm(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_RatdmRollback(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0214 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define RATADP_RatdmRollback(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_RatdmDlvrDL_PD(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0314 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define RATADP_RatdmDlvrDL_PD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_RatdmDlvrDL_BD(v1, v2) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0414 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define RATADP_RatdmDlvrDL_BD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UL_TFT_Match(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0514 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_UL_TFT_Match(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DL_LoopbackCpy(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0614 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_DL_LoopbackCpy(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DlvrDL_SDUs(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0714 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_DlvrDL_SDUs(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RcvUL(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0814 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RcvUL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RcvUL_SDUs(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0914 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RcvUL_SDUs(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UL_TFT_CYCLES(v1, v2) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0A14 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define UPCM_UL_TFT_CYCLES(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_CheckEmptyTCPAck(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0B14 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_CheckEmptyTCPAck(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_V4Content1(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0C14 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_V4Content1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_V4Content2(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0D14 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_V4Content2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_V6Content1(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0E14 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define TFTPF_V6Content1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_V6Content2(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0F14 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_V6Content2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_V6Content3(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x1014 | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_V6Content3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_Match1(v1, v2) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1114 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_Match1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_Match2(v1, v2) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1214 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_Match2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchPort(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x1314 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define TFTPF_MatchPort(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchProtocol(v1, v2) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1414 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_MatchProtocol(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchSPI(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1514 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_MatchSPI(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchIPAddr(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x1614 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TFTPF_MatchIPAddr(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchTOS(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1714 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_MatchTOS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchFrag(v1) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x1814 | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_MatchFrag(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchFlowLabel(v1, v2, v3) do {\
		if(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1 && (NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1914 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define TFTPF_MatchFlowLabel(v1, v2, v3)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char NAS_DATA_PATH_DETAIL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RATADP_RcvULDummy(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RATADP_ToRatdm(short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_RATADP_RatdmRollback(short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_RATADP_RatdmDlvrDL_PD(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_RATADP_RatdmDlvrDL_BD(short v1, unsigned long v2);
void L1TRC_Send_UPCM_UL_TFT_Match(short v1, long v2, char v3);
void L1TRC_Send_UPCM_DL_LoopbackCpy(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UPCM_DlvrDL_SDUs(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_RcvUL(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_RcvUL_SDUs(short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_UPCM_UL_TFT_CYCLES(unsigned short v1, unsigned long v2);
void L1TRC_Send_TFTPF_CheckEmptyTCPAck(unsigned short v1, long v2, unsigned long v3, char v4);
void L1TRC_Send_TFTPF_V4Content1(unsigned short v1, long v2, unsigned long v3, char v4);
void L1TRC_Send_TFTPF_V4Content2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TFTPF_V6Content1(unsigned short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_TFTPF_V6Content2(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TFTPF_V6Content3(short v1, unsigned long v2, unsigned long v3, char v4);
void L1TRC_Send_TFTPF_Match1(short v1, long v2);
void L1TRC_Send_TFTPF_Match2(short v1, long v2);
void L1TRC_Send_TFTPF_MatchPort(short v1, long v2, long v3, long v4);
void L1TRC_Send_TFTPF_MatchProtocol(short v1, long v2);
void L1TRC_Send_TFTPF_MatchSPI(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TFTPF_MatchIPAddr(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_TFTPF_MatchTOS(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_TFTPF_MatchFrag(short v1);
void L1TRC_Send_TFTPF_MatchFlowLabel(short v1, unsigned long v2, unsigned long v3);

void Set_NAS_DATA_PATH_DETAIL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_NAS_DATA_PATH_DETAIL()	(NAS_DATA_PATH_DETAIL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()	(ChkL1ModFltr_NAS_DATA_PATH_DETAIL()&&((NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()	(ChkL1ModFltr_NAS_DATA_PATH_DETAIL()&&((NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH_DETAIL()&&((NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()	(ChkL1ModFltr_NAS_DATA_PATH_DETAIL()&&((NAS_DATA_PATH_DETAIL_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_RATADP_RcvULDummy()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()
#define ChkL1MsgFltr_RATADP_ToRatdm()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()
#define ChkL1MsgFltr_RATADP_RatdmRollback()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()
#define ChkL1MsgFltr_RATADP_RatdmDlvrDL_PD()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()
#define ChkL1MsgFltr_RATADP_RatdmDlvrDL_BD()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_RATADP()
#define ChkL1MsgFltr_UPCM_UL_TFT_Match()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()
#define ChkL1MsgFltr_UPCM_DL_LoopbackCpy()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()
#define ChkL1MsgFltr_UPCM_DlvrDL_SDUs()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()
#define ChkL1MsgFltr_UPCM_RcvUL()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_RcvUL_SDUs()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()
#define ChkL1MsgFltr_UPCM_UL_TFT_CYCLES()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_UPCM()
#define ChkL1MsgFltr_TFTPF_CheckEmptyTCPAck()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_V4Content1()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_V4Content2()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_V6Content1()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_V6Content2()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_V6Content3()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_Match1()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_Match2()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchPort()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchProtocol()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchSPI()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchIPAddr()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchTOS()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchFrag()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()
#define ChkL1MsgFltr_TFTPF_MatchFlowLabel()	ChkL1ClsFltr_NAS_DATA_PATH_DETAIL_TFTPF()


#endif
