#ifndef L1TRC_NAS_DATA_PATH_DEF_H
#define L1TRC_NAS_DATA_PATH_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_UL_Hook(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0013 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RATADP_UL_Hook(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_UL_Leave23toLTE(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0113 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RATADP_UL_Leave23toLTE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_UL_OtherTo23(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0213 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RATADP_UL_OtherTo23(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define RATADP_UG_ReadyInd(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0313 | ((short)(v1) << 16));\
	} while(0)
#else
	#define RATADP_UG_ReadyInd(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RESET_EPSB(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0413 | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_RESET_EPSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UL_TFT_NoMatch(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x0513 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_UL_TFT_NoMatch(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DispatchUL(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0613 | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_DispatchUL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RCV_UL_SUSPEND(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0713 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_RCV_UL_SUSPEND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ProcPF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0813 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_ProcPF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ProcBearer(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0913 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_ProcBearer(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBind(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0A13 | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_UnBind(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBindRcv(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0B13 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_UnBindRcv(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_UnBindRsp(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0C13 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_UnBindRsp(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_Bind(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0D13 | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_Bind(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindRsp(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0E13 | ((short)(v1) << 16), (kal_uint32)((short)(v4)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UPCM_BindRsp(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindFail(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0F13 | ((short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_BindFail(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_BindWthTest(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1013 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_BindWthTest(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_SuspendResume(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1113 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_SuspendResume(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RollbackSDUs(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x1213 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RollbackSDUs(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_NotifyLTE_Tick(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1313 | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_NotifyLTE_Tick(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_RcvUL_SDUsEBI(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x1413 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UPCM_RcvUL_SDUsEBI(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DropUL_SDUs(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1513 | ((short)(v1) << 16));\
	} while(0)
#else
	#define UPCM_DropUL_SDUs(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TEST_MODE_DL(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1613 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_TEST_MODE_DL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_ActvTestMode(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1713 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_ActvTestMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_DeActvTestMode(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1813 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_DeActvTestMode(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TestModeFail(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1913 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define UPCM_TestModeFail(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UPCM_TestLoopAct(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1A13 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define UPCM_TestLoopAct(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_AddPFLink(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1B13 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_AddPFLink(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_RemovePFLink(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1C13 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_RemovePFLink(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_GetNoPF_EBI(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x1D13 | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_GetNoPF_EBI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_ActvEPSB(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1E13 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define TFTPF_ActvEPSB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DeactEPSB(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x1F13 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define TFTPF_DeactEPSB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_AddPF(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x2013 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define TFTPF_AddPF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_ReplacePF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x2113 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define TFTPF_ReplacePF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DelPF(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x2213 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define TFTPF_DelPF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_SetDftMatch(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2313 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_SetDftMatch(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DelAll(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2413 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_DelAll(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PF_NotFound(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x2513 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define TFTPF_PF_NotFound(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PF_Link_AllocFail(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x2613 | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_PF_Link_AllocFail(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPktFilter1(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x2713 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpPktFilter1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpIPAddr(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x2813 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpIPAddr(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpIPAddrMsk(v1, v2, v3, v4) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x2913 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define TFTPF_DumpIPAddrMsk(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFProtocol(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2A13 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_DumpPFProtocol(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFPort(v1, v2, v3) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x2B13 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define TFTPF_DumpPFPort(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFSPI(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2C13 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFSPI(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFTOS(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2D13 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFTOS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_DumpPFFlowLabel(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2E13 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define TFTPF_DumpPFFlowLabel(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_PktCorrupted(v1, v2) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x2F13 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define TFTPF_PktCorrupted(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define TFTPF_MatchCorrupted(v1) do {\
		if(NAS_DATA_PATH_Trace_Filter[0]==1 && (NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_1_word(0x3013 | ((short)(v1) << 16));\
	} while(0)
#else
	#define TFTPF_MatchCorrupted(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char NAS_DATA_PATH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_RATADP_UL_Hook(short v1);
void L1TRC_Send_RATADP_UL_Leave23toLTE(short v1);
void L1TRC_Send_RATADP_UL_OtherTo23(short v1);
void L1TRC_Send_RATADP_UG_ReadyInd(short v1);
void L1TRC_Send_UPCM_RESET_EPSB(short v1);
void L1TRC_Send_UPCM_UL_TFT_NoMatch(short v1, char v2);
void L1TRC_Send_UPCM_DispatchUL(short v1);
void L1TRC_Send_UPCM_RCV_UL_SUSPEND(short v1, char v2, unsigned long v3);
void L1TRC_Send_UPCM_ProcPF(short v1, long v2, char v3);
void L1TRC_Send_UPCM_ProcBearer(unsigned short v1, long v2, char v3);
void L1TRC_Send_UPCM_UnBind(short v1);
void L1TRC_Send_UPCM_UnBindRcv(short v1, long v2, char v3);
void L1TRC_Send_UPCM_UnBindRsp(short v1, short v2);
void L1TRC_Send_UPCM_Bind(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_UPCM_BindRsp(short v1, long v2, unsigned long v3, short v4);
void L1TRC_Send_UPCM_BindFail(short v1, short v2);
void L1TRC_Send_UPCM_BindWthTest(short v1, char v2);
void L1TRC_Send_UPCM_SuspendResume(short v1, char v2);
void L1TRC_Send_UPCM_RollbackSDUs(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_NotifyLTE_Tick(short v1);
void L1TRC_Send_UPCM_RcvUL_SDUsEBI(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UPCM_DropUL_SDUs(short v1);
void L1TRC_Send_UPCM_TEST_MODE_DL(short v1, char v2, char v3);
void L1TRC_Send_UPCM_ActvTestMode(short v1, char v2);
void L1TRC_Send_UPCM_DeActvTestMode(short v1, char v2);
void L1TRC_Send_UPCM_TestModeFail(short v1, char v2);
void L1TRC_Send_UPCM_TestLoopAct(short v1, long v2, char v3);
void L1TRC_Send_TFTPF_AddPFLink(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_RemovePFLink(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_GetNoPF_EBI(short v1);
void L1TRC_Send_TFTPF_ActvEPSB(short v1, long v2, char v3);
void L1TRC_Send_TFTPF_DeactEPSB(short v1, long v2, char v3);
void L1TRC_Send_TFTPF_AddPF(short v1, char v2, long v3, long v4);
void L1TRC_Send_TFTPF_ReplacePF(short v1, char v2, long v3);
void L1TRC_Send_TFTPF_DelPF(short v1, char v2, long v3);
void L1TRC_Send_TFTPF_SetDftMatch(short v1, long v2);
void L1TRC_Send_TFTPF_DelAll(short v1, char v2);
void L1TRC_Send_TFTPF_PF_NotFound(short v1, long v2);
void L1TRC_Send_TFTPF_PF_Link_AllocFail(short v1);
void L1TRC_Send_TFTPF_DumpPktFilter1(short v1, long v2, char v3, long v4);
void L1TRC_Send_TFTPF_DumpIPAddr(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_TFTPF_DumpIPAddrMsk(short v1, unsigned long v2, long v3, unsigned long v4);
void L1TRC_Send_TFTPF_DumpPFProtocol(short v1, char v2);
void L1TRC_Send_TFTPF_DumpPFPort(short v1, long v2, long v3);
void L1TRC_Send_TFTPF_DumpPFSPI(short v1, unsigned long v2);
void L1TRC_Send_TFTPF_DumpPFTOS(unsigned short v1, unsigned long v2);
void L1TRC_Send_TFTPF_DumpPFFlowLabel(short v1, unsigned long v2);
void L1TRC_Send_TFTPF_PktCorrupted(short v1, char v2);
void L1TRC_Send_TFTPF_MatchCorrupted(short v1);

void Set_NAS_DATA_PATH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_NAS_DATA_PATH()	(NAS_DATA_PATH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_NAS_DATA_PATH_RATADP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()	(ChkL1ModFltr_NAS_DATA_PATH()&&((NAS_DATA_PATH_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_RATADP_UL_Hook()	ChkL1ClsFltr_NAS_DATA_PATH_RATADP()
#define ChkL1MsgFltr_RATADP_UL_Leave23toLTE()	ChkL1ClsFltr_NAS_DATA_PATH_RATADP()
#define ChkL1MsgFltr_RATADP_UL_OtherTo23()	ChkL1ClsFltr_NAS_DATA_PATH_RATADP()
#define ChkL1MsgFltr_RATADP_UG_ReadyInd()	ChkL1ClsFltr_NAS_DATA_PATH_RATADP()
#define ChkL1MsgFltr_UPCM_RESET_EPSB()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UL_TFT_NoMatch()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_DispatchUL()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_RCV_UL_SUSPEND()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ProcPF()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ProcBearer()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBind()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBindRcv()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_UnBindRsp()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_Bind()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindRsp()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindFail()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_BindWthTest()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_SuspendResume()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_RollbackSDUs()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_DUMP()
#define ChkL1MsgFltr_UPCM_NotifyLTE_Tick()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_RcvUL_SDUsEBI()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_DropUL_SDUs()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TEST_MODE_DL()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_ActvTestMode()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_DeActvTestMode()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TestModeFail()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_UPCM_TestLoopAct()	ChkL1ClsFltr_NAS_DATA_PATH_UPCM_INFO()
#define ChkL1MsgFltr_TFTPF_AddPFLink()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_RemovePFLink()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_GetNoPF_EBI()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_ActvEPSB()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DeactEPSB()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_AddPF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_ReplacePF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DelPF()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_SetDftMatch()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DelAll()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_PF_NotFound()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_PF_Link_AllocFail()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_INFO()
#define ChkL1MsgFltr_TFTPF_DumpPktFilter1()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpIPAddr()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpIPAddrMsk()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFProtocol()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFPort()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFSPI()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFTOS()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_DumpPFFlowLabel()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_PktCorrupted()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()
#define ChkL1MsgFltr_TFTPF_MatchCorrupted()	ChkL1ClsFltr_NAS_DATA_PATH_TFTPF_DUMP()


#endif
