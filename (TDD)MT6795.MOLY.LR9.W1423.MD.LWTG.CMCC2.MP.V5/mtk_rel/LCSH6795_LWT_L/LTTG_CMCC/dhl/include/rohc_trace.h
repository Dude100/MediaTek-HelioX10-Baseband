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
			l2trc_send_4_word(0x0015 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_ADD_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_DEL_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CFG_RST_NON_EXISTED_INST(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0715 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0815 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_PHASE1_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0915 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_REJECT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_CNTXT_NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C15 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_MODE_REJECT_WRONG_PROFILE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0D15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_REJECT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_ACCEPT_ALLOWED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1015 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UPDATE_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1115 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1215 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_SEQ_WITH_UPDT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TMO_IN_SO(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TMO_IN_SO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1415 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_NACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1515 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_SNACK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1615 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CNSM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_SET_DFLT_TS_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1815 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_UPDTE_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK_UP_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1A15 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1B15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1C15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x1D15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK1_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1E15 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1F15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_TREAT_SNACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2115 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_NUM_NOT_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2315 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_ACK_TYPE_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_RTP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CHNG_UNCOMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2615 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2715 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_CREATE_PORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MATCH_REJECT_CNTXT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_ADD_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_DEL_RTP_FLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2B15 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV4(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_5_word(0x2C15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_IPV6(v1, v2, v3, v4, v5)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2D15 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2E15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_REG_RTP_FLOW_MATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2F15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_ECN_USED(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3015 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3115 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3215 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3315 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3415 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3515 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_OUT_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3615 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3715 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3815 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3915 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_DF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3A15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3B15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TOS_TC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3C15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_DSCP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3D15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_IP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3E15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV6_TTL_HOPL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3F15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_INNER_IPV4_IPID_BHVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_CHECKSUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4115 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RES_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4215 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ECN_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4315 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4415 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_FLAG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4515 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAGS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4615 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_WINDOW(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4715 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_URG_PTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4915 | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_UPDT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_OPT_DEL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4B15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_ACK_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4C15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_SEQ_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4D15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PAD_BIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4E15 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_EXTENSION(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_P2NULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_NULL2P(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_CHANGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_MARKER_TOGGLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5315 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_PT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021_INF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5515 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_OFF_TS_STRIDE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_SCLD_LSB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TSC_IND_021(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_WRAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_TS_TMR_BSD_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5B15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_UPDATE_TIME_STRIDE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5C15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_INSERT_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5D15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_REMOVE_ONLY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5E15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_RM_THEN_INS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_RTP_LIST_GENERIC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_UDP_ERR_SEL_EXT2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_ENC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6315 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RCVD_FDBK2_OPT_INVALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6415 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PTRN_TCP_RSF_FLAG_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_IP_VER(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNKNOWN_IP_VER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_GET_STATIC_FIELD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6715 | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define ROHC_LOG_CNTXT_REPLACE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6815 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_PARAM_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6915 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6A15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV6_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6B15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_UDP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6C15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_HDR_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6D15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_EOL_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6E15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_SIZE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6F15 | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_TCP_OPT_END_ERR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7015 | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_COMP_PARSE_IPV4_FLAG_FRAG_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV4_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IPV6_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_C_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7415 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_REF_CSRC_LIST_UNDERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7515 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_C_LOG_RM_CSRC_LIST_OVERRUN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_OUTER_IP_INFO_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CNTXT_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_OK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_HAPPEN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_REPAIR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7B15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC3_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC7_OK_FC_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7D15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_CRC_OK_FC_CR_TRG_ACK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7E15 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_FDBK_ACK_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7F15 | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_PRODUCE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8015 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_REPLACED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8115 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_D_REF_LIST_INSERTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8215 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8315 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_FDBK_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_DONE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_V2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_PARSE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NOT_ALLOW_HEADER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8A15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_RCVD_MODE_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8B15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8C15 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_CNTXT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8D15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_MATCH_NO_CNTXT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8E15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_INIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8F15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_NO_NEED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9015 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_MODE_TRAN_CANCEL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9115 | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_MATCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_TOO_LARGE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_BUF_FULL(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_BUF_FULL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9415 | ((unsigned short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SUPRESS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CRC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CRC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_SIZE_VER_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_FDBK_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_FDBK_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PARSE_CID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PARSE_CID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9A15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV1_PARSE_IP_IN_STATIC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_D_STATE_TRAN(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9B15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_D_STATE_TRAN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9C15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_VALUE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9D15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9E15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_CID_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9F15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_IR_DEC_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_SDVL_LSB_DEC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_ROHCV2_SDVL_DEC_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_COUNT_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_REF_EXHAUSTED(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_REF_ID_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_RM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_THEN_INS_INS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_INS_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAA15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAB15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_INS_ONLY_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAC15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAD15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_RM_ONLY_RM_NUM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAE15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_PARSE_GP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAF15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DST_SIZE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_DUP_IDX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_LIST_GEN_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_LIST_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TS_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TIME_STRIDE_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_EXT_TSC_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBA15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBB15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV1_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBC15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_PARSE_DYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBD15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBE15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_RTP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBF15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IP2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_UDP_ROHCV1_EXT_IPX2_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC215 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC315 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC415 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UDP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC515 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_UNCOMP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC615 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC715 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV1_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC815 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_IP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC915 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCA15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_CR_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCB15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IRDYN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCC15 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ROHC_LOG_TCP_BCID_NO_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCD15 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_PROFILE_NOT_SUPPORT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xCE15 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ROHC_LOG_TCP_REP_CNTXT_CPY_FAIL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCF15 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPTIONS_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD015 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_ROHCV2_CHK_IR_IP_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD115 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_TCP_OPT_RSVD_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD215 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_NOT_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_PROFILE_SUPPORT(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD315 | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define ROHC_LOG_PROFILE_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ROHC_LOG_UNKNOWN_CID(v1) do {\
		if(ROHC_Trace_Filter[0]==1 && (ROHC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD415 | ((short)(v1) << 16));\
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
void L1TRC_Send_ROHC_LOG_C_REG_RTP_FLOW_UDP_RTP(unsigned short v1, unsigned long v2, unsigned long v3);
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
