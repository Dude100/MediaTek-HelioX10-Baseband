#ifndef L1TRC_ERLCUL_DEF_H
#define L1TRC_ERLCUL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_GENERIC(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0008 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_GENERIC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_BUF_USAGE(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0108 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_NACK_BUF_USAGE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_ERROR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0208 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_GRANT_IND(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0308 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_GRANT_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FIRST_SDU_SZ(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x0408 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_FIRST_SDU_SZ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SDU_SZ(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0508 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEG_SDU_SZ(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0608 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SEG_SDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SCH_RESULT(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0708 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_SCH_RESULT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SCH_RESULT_PAD(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0808 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SCH_RESULT_PAD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_AM_SN(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0908 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_AM_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UM5_SN(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0A08 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_UM5_SN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_UM10_SN(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0B08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_UM10_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RESEG_IN(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0C08 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_RESEG_IN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEND_RETX_PDU(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0D08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_SEND_RETX_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEND_RETX_SEG(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0E08 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_SEND_RETX_SEG(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_RETX(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x0F08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_MAX_RETX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEND_STUS_PDU(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1008 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_SEND_STUS_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REGEN_STUS_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1108 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REGEN_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEG_STUS_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1208 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_SEG_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DUP_STUS_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1308 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DUP_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PDU_IND_1(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1408 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PDU_IND_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PDU_IND_2(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1508 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PDU_IND_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VT_A_UPDATE(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1608 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VT_A_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_NACK_SO(v1, v2, v3, v4) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x1708 | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_NACK_SO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_RCVD_B4(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1808 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_NACK_RCVD_B4(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_PDU(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1908 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_NACK_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_SEG(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1A08 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_NACK_SEG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_AFTER_SEG(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1B08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_NACK_AFTER_SEG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_AFTER_SEG_LSF(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x1C08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_NACK_AFTER_SEG_LSF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SEND_SRB_CNF(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1D08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_SEND_SRB_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDCP_DISCARD(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1E08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_PDCP_DISCARD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DISCARD_SDU(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1F08 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DISCARD_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_STUS_PROH(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2008 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_STUS_PROH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_START(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2108 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_STOP(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2208 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2308 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2408 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2508 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2608 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_FAKE(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2708 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_FAKE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_RETX_EXPRY_MULTI(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2808 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_RETX_EXPRY_MULTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_START(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2908 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_RESTART(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2A08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_RESTART(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_IDC_END(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2B08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_IDC_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDU_RETX_CNTR(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x2C08 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_PDU_RETX_CNTR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_RETX_CNTR(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2D08 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_MAX_RETX_CNTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RST_COPRO_IDX(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2E08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RST_COPRO_IDX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_POLL_IN_COPRO_OFF(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x2F08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_POLL_IN_COPRO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_START_EVENT(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3008 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_START_EVENT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_HWB_REL_FOR_NO_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3108 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_HWB_REL_FOR_NO_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_SRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3208 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_DRB_1(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3308 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_DRB_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_ADD_DRB_2(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3408 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_ADD_DRB_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_SRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3508 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_DRB(v1, v2) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3608 | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_DRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_OLD_DRB(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3708 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_OLD_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_DEL_NEW_DRB(v1, v2, v3) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3808 | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_UL_DEL_NEW_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RECFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3908 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RECFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_REEST_WI_CFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3A08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_REEST_WI_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_REEST_WO_CFG_RB(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3B08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_REEST_WO_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RB_PARAM_ERR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3C08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RB_PARAM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_RB_STUS_ERR(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3D08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_RB_STUS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_UL_HWB_ALLOC_NUM(v1) do {\
		if(ERLCUL_Trace_Filter[0]==1 && (ERLCUL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x3E08 | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_UL_HWB_ALLOC_NUM(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ERLCUL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ERLC_LOG_GENERIC(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_NACK_BUF_USAGE(short v1, long v2);
void L1TRC_Send_ERLC_LOG_ERROR(short v1);
void L1TRC_Send_ERLC_LOG_GRANT_IND(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_FIRST_SDU_SZ(short v1, long v2);
void L1TRC_Send_ERLC_LOG_SDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_SEG_SDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_SCH_RESULT(short v1, long v2);
void L1TRC_Send_ERLC_LOG_SCH_RESULT_PAD(short v1);
void L1TRC_Send_ERLC_LOG_UL_AM_SN(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_UM5_SN(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_UL_UM10_SN(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RESEG_IN(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_SEND_RETX_PDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_SEND_RETX_SEG(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_MAX_RETX(short v1);
void L1TRC_Send_ERLC_LOG_SEND_STUS_PDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_REGEN_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_SEG_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_DUP_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_STUS_PDU_IND_1(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_STUS_PDU_IND_2(short v1, long v2);
void L1TRC_Send_ERLC_LOG_VT_A_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_INVALID_NACK_SO(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_NACK_RCVD_B4(short v1);
void L1TRC_Send_ERLC_LOG_NACK_PDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_NACK_SEG(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_NACK_AFTER_SEG(short v1, long v2);
void L1TRC_Send_ERLC_LOG_NACK_AFTER_SEG_LSF(short v1, long v2);
void L1TRC_Send_ERLC_LOG_SEND_SRB_CNF(short v1, long v2);
void L1TRC_Send_ERLC_LOG_PDCP_DISCARD(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DISCARD_SDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_STUS_PROH(short v1, long v2);
void L1TRC_Send_ERLC_LOG_POLL_RETX_START(short v1, long v2);
void L1TRC_Send_ERLC_LOG_POLL_RETX_STOP(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_NO_SDU(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_FAKE(short v1);
void L1TRC_Send_ERLC_LOG_POLL_RETX_EXPRY_MULTI(short v1);
void L1TRC_Send_ERLC_LOG_IDC_START(short v1);
void L1TRC_Send_ERLC_LOG_IDC_RESTART(short v1);
void L1TRC_Send_ERLC_LOG_IDC_END(short v1);
void L1TRC_Send_ERLC_LOG_PDU_RETX_CNTR(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_MAX_RETX_CNTR(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_RST_COPRO_IDX(short v1);
void L1TRC_Send_ERLC_LOG_UL_POLL_IN_COPRO_OFF(short v1);
void L1TRC_Send_ERLC_LOG_START_EVENT(short v1);
void L1TRC_Send_ERLC_LOG_HWB_REL_FOR_NO_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_ADD_SRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_ADD_DRB_1(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_ADD_DRB_2(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_UL_DEL_SRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_DEL_DRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_UL_DEL_OLD_DRB(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_UL_DEL_NEW_DRB(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_UL_RECFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_REEST_WI_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_REEST_WO_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_UL_RB_PARAM_ERR(short v1);
void L1TRC_Send_ERLC_LOG_UL_RB_STUS_ERR(short v1);
void L1TRC_Send_ERLC_LOG_UL_HWB_ALLOC_NUM(short v1);

void Set_ERLCUL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ERLCUL()	(ERLCUL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()	(ChkL1ModFltr_ERLCUL()&&((ERLCUL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()	(ChkL1ModFltr_ERLCUL()&&((ERLCUL_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ERLC_LOG_GENERIC()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_BUF_USAGE()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_ERROR()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_GRANT_IND()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_FIRST_SDU_SZ()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SDU_SZ()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SEG_SDU_SZ()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SCH_RESULT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SCH_RESULT_PAD()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_AM_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_UM5_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_UM10_SN()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RESEG_IN()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SEND_RETX_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SEND_RETX_SEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MAX_RETX()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SEND_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_REGEN_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SEG_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DUP_STUS_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PDU_IND_1()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PDU_IND_2()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_VT_A_UPDATE()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_NACK_SO()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_RCVD_B4()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_SEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_AFTER_SEG()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_AFTER_SEG_LSF()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_SEND_SRB_CNF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_PDCP_DISCARD()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DISCARD_SDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_STUS_PROH()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_STOP()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_ADD_PDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_NO_SDU()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_NO_LOSS()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_FAKE()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_RETX_EXPRY_MULTI()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_START()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_RESTART()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_IDC_END()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_PDU_RETX_CNTR()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_MAX_RETX_CNTR()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RST_COPRO_IDX()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_POLL_IN_COPRO_OFF()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_START_EVENT()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_HWB_REL_FOR_NO_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_SRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_DRB_1()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_ADD_DRB_2()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_SRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_OLD_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_DEL_NEW_DRB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RECFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_REEST_WI_CFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_REEST_WO_CFG_RB()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RB_PARAM_ERR()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_RB_STUS_ERR()	ChkL1ClsFltr_ERLCUL_ERLCUL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_UL_HWB_ALLOC_NUM()	ChkL1ClsFltr_ERLCUL_ERLCUL_DUMP()


#endif
