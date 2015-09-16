#ifndef L1TRC_ROHC_DEF_H
#define L1TRC_ROHC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_GENERIC(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0016 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0716 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0816 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0916 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C16 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0D16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1016 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1116 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1216 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TMO_IN_SO(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TMO_IN_SO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1416 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1516 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1616 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1816 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1A16 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1B16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1C16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1D16 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1E16 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1F16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2116 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2316 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2616 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2716 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2B16 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0x2C16 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2D16 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2E16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2F16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3016 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3116 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3216 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3316 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3416 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3516 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3616 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3716 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3816 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3916 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3A16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3B16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3C16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3D16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3E16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3F16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4116 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4216 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4316 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4416 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4516 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4616 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4716 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4916 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4B16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4C16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4D16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4E16 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5316 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5516 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5B16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5C16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5D16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5E16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6316 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6416 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_IP_VER(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNKNOWN_IP_VER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6716 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6816 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6916 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6A16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6B16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6C16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6D16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6E16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6F16 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7016 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7416 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7516 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7B16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7D16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7E16 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7F16 | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8016 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8116 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8216 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8316 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8A16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8B16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8C16 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8D16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8E16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8F16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9016 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9116 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_BUF_FULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_BUF_FULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9416 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CRC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CRC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9A16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9B16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9C16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9D16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9E16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9F16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAA16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAB16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAC16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAD16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAE16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAF16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBA16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBB16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBC16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBD16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBE16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBF16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC216 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC316 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC516 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC616 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC716 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC816 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC916 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCA16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCB16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCC16 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCD16 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCE16 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCF16 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD016 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD116 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD216 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD316 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_CID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD416 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNKNOWN_CID(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ROHC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ROHC_LOG_GENERIC(short v1, long v2, long v3, long v4);
void L1TRC_Send_ROHC_LOG_CFG_ADD_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_DEL_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_RST_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_ADD_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_DEL_NON_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_CFG_RST_NON_EXISTED_INST(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_PHASE1_START(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_PHASE1_END(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_MODE_TRAN_REJECT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_C_MODE_TRAN_DONE(short v1);
void L1TRC_Send_ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(short v1);
void L1TRC_Send_ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(short v1);
void L1TRC_Send_ROHC_LOG_C_STATE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_UPDATE_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_TMO_IN_SO(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_NACK(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_SNACK(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_FDBK_CNSM(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_SET_DFLT_TS_STRIDE(short v1);
void L1TRC_Send_ROHC_LOG_C_UPDTE_TS_STRIDE(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_INFO_1(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_INFO_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CHNG_RTP(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CHNG_UNCOMP(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CREATE(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_C_CNTXT_CREATE_PORT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_MATCH_REJECT_CNTXT(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_ADD_RTP_FLOW(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_DEL_RTP_FLOW(short v1);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_IPV4(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_IPV6(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(unsigned short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_MATCH(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_ECN_USED(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_DF(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_DSCP(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_DF(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_DSCP(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_UDP_CHECKSUM(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RES_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ECN_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_URG_FLAG(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ACK_FLAG(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RSF_FLAGS(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_WINDOW(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_URG_PTR(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_RESET(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_UPDT(short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_OPT_DEL(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_ACK_STRIDE(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_SEQ_STRIDE(short v1, long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_PAD_BIT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_EXTENSION(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_P2NULL(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_NULL2P(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_CHANGE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_PT(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TSC_IND_021(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_WRAP(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_RTP_LIST_GENERIC(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_ENC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RCVD_FDBK2_OPT_INVALID(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(unsigned short v1);
void L1TRC_Send_ROHC_LOG_UNKNOWN_IP_VER(short v1);
void L1TRC_Send_ROHC_LOG_GET_STATIC_FIELD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CNTXT_REPLACE(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_ROHC_LOG_PARAM_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(unsigned short v1);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(unsigned short v1, unsigned long v2);
void L1TRC_Send_ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_C_CNTXT_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(short v1, long v2);
void L1TRC_Send_ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CNTXT_ALLOC_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_OK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_HAPPEN(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_REPAIR_FAIL(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(short v1);
void L1TRC_Send_ROHC_LOG_D_FDBK_ACK_NUM(unsigned short v1);
void L1TRC_Send_ROHC_LOG_FDBK_PRODUCE(unsigned short v1, long v2);
void L1TRC_Send_ROHC_LOG_D_REF_LIST_REPLACED(unsigned short v1);
void L1TRC_Send_ROHC_LOG_D_REF_LIST_INSERTED(unsigned short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_FDBK_START(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_FDBK_END(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_DONE(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_PARSE_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_MODE_MATCH_CNTXT(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_MODE_MATCH_NO_CNTXT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_INIT(short v1, long v2);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_NO_NEED(short v1);
void L1TRC_Send_ROHC_LOG_MODE_TRAN_CANCEL(short v1, long v2);
void L1TRC_Send_ROHC_LOG_TCP_BCID_MATCH(short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_TOO_LARGE(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_BUF_FULL(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_SUPRESS(unsigned short v1, unsigned long v2, long v3);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_CRC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_SIZE_VER_ERR(short v1);
void L1TRC_Send_ROHC_LOG_FDBK_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_PARSE_CID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_D_STATE_TRAN(short v1, long v2);
void L1TRC_Send_ROHC_LOG_CID_SDVL_VALUE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_DEC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IR_DEC_FAIL(short v1, long v2);
void L1TRC_Send_ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_REF_EXHAUSTED(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_PARSE_GP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_DST_SIZE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_DUP_IDX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_LIST_GEN_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_BCID_NO_MATCH(short v1, long v2);
void L1TRC_Send_ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(short v1, long v2, long v3);
void L1TRC_Send_ROHC_LOG_TCP_OPTIONS_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(short v1);
void L1TRC_Send_ROHC_LOG_TCP_OPT_RSVD_ERR(short v1);
void L1TRC_Send_ROHC_LOG_PROFILE_NOT_SUPPORT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_PROFILE_SUPPORT(unsigned short v1);
void L1TRC_Send_ROHC_LOG_UNKNOWN_CID(short v1);

void Set_ROHC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ROHC()	(ROHC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ROHC_ROHC_INFO()	(ChkL1ModFltr_ROHC()&&((ROHC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ROHC_ROHC_DUMP()	(ChkL1ModFltr_ROHC()&&((ROHC_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ROHC_LOG_GENERIC()	ChkL1ClsFltr_ROHC_ROHC_DUMP()
#define ChkL1MsgFltr_ROHC_LOG_CFG_ADD_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_DEL_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_RST_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_ADD_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_DEL_NON_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CFG_RST_NON_EXISTED_INST()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_PHASE1_START()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_PHASE1_END()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_TRAN_REJECT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_TRAN_DONE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_REJECT_CNTXT_NULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_REJECT_ALLOWED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_STATE_TRAN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UPDATE_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TMO_IN_SO()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_NACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CNSM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_SET_DFLT_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_UPDTE_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_INFO_1()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_INFO_2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_TREAT_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_INFO_1()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_INFO_2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_TREAT_SNACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CHNG_RTP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CHNG_UNCOMP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CREATE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_CREATE_PORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MATCH_REJECT_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_ADD_RTP_FLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_DEL_RTP_FLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_IPV4()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_IPV6()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_REG_RTP_FLOW_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_ECN_USED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_DF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV6_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_DSCP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_DF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_TOS_TC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_DSCP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_UDP_CHECKSUM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RES_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ECN_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_URG_FLAG()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ACK_FLAG()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RSF_FLAGS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_WINDOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_URG_PTR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_RESET()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_UPDT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_OPT_DEL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_ACK_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_SEQ_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_PAD_BIT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_EXTENSION()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_P2NULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_NULL2P()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_CHANGE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_MARKER_TOGGLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_PT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TSC_IND_021_INF()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_SCLD_LSB()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TSC_IND_021()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_WRAP()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_RTP_LIST_GENERIC()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_ENC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_ENC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RCVD_FDBK2_OPT_INVALID()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNKNOWN_IP_VER()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_GET_STATIC_FIELD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CNTXT_REPLACE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PARAM_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_C_CNTXT_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_C_LOG_RM_CSRC_LIST_OVERRUN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CNTXT_ALLOC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_OK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_HAPPEN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_REPAIR_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC3_OK_FC_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC7_OK_FC_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_FDBK_ACK_NUM()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_PRODUCE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_REF_LIST_REPLACED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_REF_LIST_INSERTED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_FDBK_START()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_FDBK_END()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_DONE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_PARSE_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_MATCH_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_MATCH_NO_CNTXT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_INIT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_NO_NEED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_MODE_TRAN_CANCEL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_BCID_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_TOO_LARGE()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_BUF_FULL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SUPRESS()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CRC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_SIZE_VER_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_FDBK_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PARSE_CID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_D_STATE_TRAN()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_VALUE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_DEC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_CID_SDVL_DEC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IR_DEC_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_COUNT_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_REF_EXHAUSTED()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_RM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_THEN_INS_INS_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_PARSE_GP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_DST_SIZE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_DUP_IDX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_LIST_GEN_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV1_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_IP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_BCID_NO_MATCH()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_OPTIONS_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_TCP_OPT_RSVD_ERR()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PROFILE_NOT_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_PROFILE_SUPPORT()	ChkL1ClsFltr_ROHC_ROHC_INFO()
#define ChkL1MsgFltr_ROHC_LOG_UNKNOWN_CID()	ChkL1ClsFltr_ROHC_ROHC_INFO()


#endif
