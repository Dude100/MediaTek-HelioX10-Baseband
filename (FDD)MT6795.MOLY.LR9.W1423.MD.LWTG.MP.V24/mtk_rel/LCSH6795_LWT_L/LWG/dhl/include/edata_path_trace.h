#ifndef L1TRC_EDATA_PATH_DEF_H
#define L1TRC_EDATA_PATH_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DUMMY_EDYN_LOG(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x0011 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define DUMMY_EDYN_LOG(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EINIT_TIME(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0111 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EINIT_TIME(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define SHOW_LTE_TICK(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0211 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define SHOW_LTE_TICK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_DSP_TIMER_LISR(v1, v2, v3) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x0311 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ENTER_DSP_TIMER_LISR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ENTER_LMAC_HNDLR(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0411 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ENTER_LMAC_HNDLR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DSP_EVENT_LISR(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0511 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define DSP_EVENT_LISR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_RESET_EPSB(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0611 | ((short)(v1) << 16));\
	} while(0)
#else
	#define LTM_RESET_EPSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_CONSTRUCT_UL_SDU(v1, v2, v3) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_3_word(0x0711 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define LTM_CONSTRUCT_UL_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_UL_TCP_ACK_COPY_FAIL(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0811 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define LTM_UL_TCP_ACK_COPY_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_QUEUE_UL_SDU(v1, v2, v3) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x0911 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define LTM_QUEUE_UL_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_EPSB_UL_Q(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_1_word(0x0A11 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define LTM_PROCESS_EPSB_UL_Q(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_PROCESS_EPSB_DL(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_4_word(0x0B11 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define LTM_PROCESS_EPSB_DL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_ROLLBACK(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0C11 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define LTM_ROLLBACK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_NXT_DRX_IND(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0D11 | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_NXT_DRX_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_EPSB_INIT(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0x0E11 | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define LTM_EPSB_INIT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_EPSB_ACT(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x0F11 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_EPSB_ACT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_EPSB_DEACT(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1011 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_EPSB_DEACT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_IDLE_ENTER(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1111 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_IDLE_ENTER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_IDLE_ENTER_CHECK(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_2_word(0x1211 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define LTM_IDLE_ENTER_CHECK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_IDLE_LEAVE(v1, v2, v3) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x10)!=0 )\
			l2trc_send_3_word(0x1311 | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v2));\
	} while(0)
#else
	#define LTM_IDLE_LEAVE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_IDLE_LEAVE_REJ(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1411 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_IDLE_LEAVE_REJ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_IDLE_LEAVE_REJ_DROP(v1, v2, v3) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1511 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_IDLE_LEAVE_REJ_DROP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_SUSPEND(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1611 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_SUSPEND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_RESUME(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1711 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_RESUME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_GEMINI_SUSPEND(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1811 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_GEMINI_SUSPEND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define LTM_GEMINI_RESUME(v1, v2) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_2_word(0x1911 | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define LTM_GEMINI_RESUME(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Timeout(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x1A11 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_Timeout(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Resume(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x1B11 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_Resume(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Stop(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_4_word(0x1C11 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_Stop(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Init(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x1D11 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_Init(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_SetAttri(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x1E11 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((short)(v3))) << 16), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_SetAttri(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Set(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x1F11 | ((short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((char)(v2))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define ETMR_Set(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_Fail(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x2011 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ETMR_Fail(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_TickByTicks(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_1_word(0x2111 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ETMR_TickByTicks(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_GetLatestExpire(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_1_word(0x2211 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ETMR_GetLatestExpire(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_ExpireEnd(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x2311 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v2)) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define ETMR_ExpireEnd(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ETMR_InitMayFail(v1, v2, v3, v4) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x20)!=0 )\
			l2trc_send_3_word(0x2411 | ((unsigned short)(v1) << 16), (kal_uint32)((short)(v3)) | (((kal_uint32)((short)(v4))) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ETMR_InitMayFail(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2COPRO_STATE_OFF_TO_ON(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2511 | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2COPRO_STATE_OFF_TO_ON(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2COPRO_STATE_ON_TO_OFF(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2611 | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2COPRO_STATE_ON_TO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2COPRO_STATE_ON_TO_WAIT_OFF(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2711 | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2COPRO_STATE_ON_TO_WAIT_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2COPRO_STATE_WAIT_OFF_TO_OFF(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2811 | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2COPRO_STATE_WAIT_OFF_TO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2COPRO_STATE_WAIT_OFF_TO_ON(v1) do {\
		if(EDATA_PATH_Trace_Filter[0]==1 && (EDATA_PATH_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2911 | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2COPRO_STATE_WAIT_OFF_TO_ON(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EDATA_PATH_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_DUMMY_EDYN_LOG(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EINIT_TIME(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_SHOW_LTE_TICK(unsigned short v1, unsigned long v2);
void L1TRC_Send_ENTER_DSP_TIMER_LISR(short v1, char v2, unsigned long v3);
void L1TRC_Send_ENTER_LMAC_HNDLR(short v1, unsigned long v2);
void L1TRC_Send_DSP_EVENT_LISR(short v1, unsigned long v2);
void L1TRC_Send_LTM_RESET_EPSB(short v1);
void L1TRC_Send_LTM_CONSTRUCT_UL_SDU(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_LTM_UL_TCP_ACK_COPY_FAIL(short v1, unsigned long v2);
void L1TRC_Send_LTM_QUEUE_UL_SDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_LTM_PROCESS_EPSB_UL_Q(unsigned short v1);
void L1TRC_Send_LTM_PROCESS_EPSB_DL(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_LTM_ROLLBACK(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_LTM_NXT_DRX_IND(unsigned short v1, char v2);
void L1TRC_Send_LTM_EPSB_INIT(short v1, long v2, long v3, char v4);
void L1TRC_Send_LTM_EPSB_ACT(short v1, char v2);
void L1TRC_Send_LTM_EPSB_DEACT(short v1, char v2);
void L1TRC_Send_LTM_IDLE_ENTER(short v1, char v2);
void L1TRC_Send_LTM_IDLE_ENTER_CHECK(short v1, long v2);
void L1TRC_Send_LTM_IDLE_LEAVE(short v1, long v2, char v3);
void L1TRC_Send_LTM_IDLE_LEAVE_REJ(short v1, char v2);
void L1TRC_Send_LTM_IDLE_LEAVE_REJ_DROP(short v1, char v2, char v3);
void L1TRC_Send_LTM_SUSPEND(short v1, char v2);
void L1TRC_Send_LTM_RESUME(short v1, char v2);
void L1TRC_Send_LTM_GEMINI_SUSPEND(short v1, char v2);
void L1TRC_Send_LTM_GEMINI_RESUME(short v1, char v2);
void L1TRC_Send_ETMR_Timeout(unsigned short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_Resume(unsigned short v1, unsigned long v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_Stop(unsigned short v1, unsigned long v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_Init(unsigned short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_SetAttri(unsigned short v1, short v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_Set(short v1, char v2, short v3, unsigned long v4);
void L1TRC_Send_ETMR_Fail(unsigned short v1, short v2, unsigned long v3, char v4);
void L1TRC_Send_ETMR_TickByTicks(unsigned short v1);
void L1TRC_Send_ETMR_GetLatestExpire(unsigned short v1);
void L1TRC_Send_ETMR_ExpireEnd(unsigned short v1, short v2, unsigned long v3, char v4);
void L1TRC_Send_ETMR_InitMayFail(unsigned short v1, unsigned long v2, short v3, short v4);
void L1TRC_Send_L2COPRO_STATE_OFF_TO_ON(short v1);
void L1TRC_Send_L2COPRO_STATE_ON_TO_OFF(short v1);
void L1TRC_Send_L2COPRO_STATE_ON_TO_WAIT_OFF(short v1);
void L1TRC_Send_L2COPRO_STATE_WAIT_OFF_TO_OFF(short v1);
void L1TRC_Send_L2COPRO_STATE_WAIT_OFF_TO_ON(short v1);

void Set_EDATA_PATH_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EDATA_PATH()	(EDATA_PATH_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EDATA_PATH_ETICK()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EDATA_PATH_EDYN_DUMP()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EDATA_PATH_LTM_INFO()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EDATA_PATH_LTM_DUMP()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EDATA_PATH_ETMR_DUMP()	(ChkL1ModFltr_EDATA_PATH()&&((EDATA_PATH_Trace_Filter[1]&0x40)!=0))
#define ChkL1MsgFltr_DUMMY_EDYN_LOG()	ChkL1ClsFltr_EDATA_PATH_EDYN_DUMP()
#define ChkL1MsgFltr_EINIT_TIME()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_SHOW_LTE_TICK()	ChkL1ClsFltr_EDATA_PATH_ETICK()
#define ChkL1MsgFltr_ENTER_DSP_TIMER_LISR()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_ENTER_LMAC_HNDLR()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_DSP_EVENT_LISR()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_LTM_RESET_EPSB()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_CONSTRUCT_UL_SDU()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_UL_TCP_ACK_COPY_FAIL()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_QUEUE_UL_SDU()	ChkL1ClsFltr_EDATA_PATH_LTM_DUMP()
#define ChkL1MsgFltr_LTM_PROCESS_EPSB_UL_Q()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_PROCESS_EPSB_DL()	ChkL1ClsFltr_EDATA_PATH_LTM_DUMP()
#define ChkL1MsgFltr_LTM_ROLLBACK()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_NXT_DRX_IND()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_EPSB_INIT()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_EPSB_ACT()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_EPSB_DEACT()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_IDLE_ENTER()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_IDLE_ENTER_CHECK()	ChkL1ClsFltr_EDATA_PATH_LTM_DUMP()
#define ChkL1MsgFltr_LTM_IDLE_LEAVE()	ChkL1ClsFltr_EDATA_PATH_LTM_DUMP()
#define ChkL1MsgFltr_LTM_IDLE_LEAVE_REJ()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_IDLE_LEAVE_REJ_DROP()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_SUSPEND()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_RESUME()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_GEMINI_SUSPEND()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_LTM_GEMINI_RESUME()	ChkL1ClsFltr_EDATA_PATH_LTM_INFO()
#define ChkL1MsgFltr_ETMR_Timeout()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_Resume()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_Stop()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_Init()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_SetAttri()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_Set()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_Fail()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_TickByTicks()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_GetLatestExpire()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_ExpireEnd()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_ETMR_InitMayFail()	ChkL1ClsFltr_EDATA_PATH_ETMR_INFO()
#define ChkL1MsgFltr_L2COPRO_STATE_OFF_TO_ON()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_L2COPRO_STATE_ON_TO_OFF()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_L2COPRO_STATE_ON_TO_WAIT_OFF()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_L2COPRO_STATE_WAIT_OFF_TO_OFF()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()
#define ChkL1MsgFltr_L2COPRO_STATE_WAIT_OFF_TO_ON()	ChkL1ClsFltr_EDATA_PATH_EDYN_INFO()


#endif
