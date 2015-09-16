#ifndef L1TRC_ERLCDL_DEF_H
#define L1TRC_ERLCDL_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDU_BUF_USAGE(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x000B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_PDU_BUF_USAGE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_R_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x010B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_R_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_MS_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x020B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_MS_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_X_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x030B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_X_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_H_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x040B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_H_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_UR_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x050B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_UR_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_UX_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x060B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_UX_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_VR_UH_UPDATE(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x070B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_VR_UH_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_START(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x080B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_START_TICK(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x090B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_START_TICK(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_STOP(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0A0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0B0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY_FAKE(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0C0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY_FAKE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_EXPRY_MULTI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0D0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_EXPRY_MULTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_HT(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0E0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_RX_HT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_MOT(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_RX_MOT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_POLL(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x100B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_RX_POLL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UNKNOWN_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x110B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_UNKNOWN_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM5_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x120B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM5_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM10_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x130B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM10_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AM_OOW_PDU(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x140B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_RX_AM_OOW_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AMD_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x150B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_RX_AMD_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AMD_SEG(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x160B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_RX_AMD_SEG(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_AMD_SEG_LSF(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x170B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_RX_AMD_SEG_LSF(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_BY_DUP_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x180B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_BY_DUP_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_POLL_BY_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x190B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_POLL_BY_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DUP_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1A0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DUP_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DUP_SEG(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1B0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DUP_SEG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_UM_PDU_DRP_N(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x1C0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_RX_UM_PDU_DRP_N(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_CHK_CMPLT_OK(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1D0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_CHK_CMPLT_OK(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_CHK_CMPLT_NG(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1E0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_CHK_CMPLT_NG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_R1(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x1F0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_R1(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_E_LI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x200B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_E_LI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_LI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x210B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_LI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_PDU_SZ(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x220B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_PDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_LI_VALUE(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x230B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_LI_VALUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FI_WO_LI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x240B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_FI_WO_LI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FI_LI_INFO(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x250B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_FI_LI_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_GEN_STUS_PDU(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x260B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_GEN_STUS_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DELAY_STUS_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x270B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DELAY_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_FORCE_STUS_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x280B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_FORCE_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_SEG_STUS_PDU(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x290B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_SEG_STUS_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_NACK(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x2A0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_NACK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_SN(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2B0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_NACK_SN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_SO(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2C0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_NACK_SO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_STUS_PDU(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2D0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_RX_STUS_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_CPT(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2E0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_CPT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_INVALID_STUS_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x2F0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_INVALID_STUS_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_AM(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x300B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_REASM_AM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_UM(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x310B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_REASM_UM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_SRB_REASM_N_SDU(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x320B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_SRB_REASM_N_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_ONE_SRB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x330B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_ONE_SRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_UM_INVALID_SDU_SZ(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x340B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_UM_INVALID_SDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_UM_INVALID_FI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x350B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_UM_INVALID_FI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_AM_INVALID_SDU_SZ(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x360B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_AM_INVALID_SDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_AM_INVALID_FI(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x370B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_AM_INVALID_FI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_INVALID_SDU_SZ(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x380B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_INVALID_SDU_SZ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_SKIP_INVALID_PDU(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x390B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_REASM_SKIP_INVALID_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_REASM_SKIP_INVALID_SN(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3A0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_REASM_SKIP_INVALID_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x3B0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_CACHE(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x3C0B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_CACHE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_OOW(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x3D0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_OOW(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_INVALID(v1, v2, v3, v4) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x3E0B | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_INVALID(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDPC_SN_VOLTE_OFF(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x3F0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDPC_SN_VOLTE_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CTRL(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x400B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CTRL(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x410B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RST_COPRO_IDX(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x420B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RST_COPRO_IDX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_POLL_IN_COPRO_OFF(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x430B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_POLL_IN_COPRO_OFF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_T_REORDER_ZERO(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x440B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_T_REORDER_ZERO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_SRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x450B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_DRB_1(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x460B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_DRB_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_ADD_DRB_2(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x470B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DL_ADD_DRB_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_SRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x480B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_SRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_DRB(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x490B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_DRB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_OLD_DRB(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4A0B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_OLD_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_DEL_NEW_DRB(v1, v2, v3) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4B0B | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define ERLC_LOG_DL_DEL_NEW_DRB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RECFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4C0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RECFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_REEST_WI_CFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4D0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_REEST_WI_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_REEST_WO_CFG_RB(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4E0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_REEST_WO_CFG_RB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RB_PARAM_ERR(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4F0B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RB_PARAM_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_RB_STUS_ERR(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x500B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_RB_STUS_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_MAX_DUP_PDU_CNTR(v1, v2) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x510B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define ERLC_LOG_MAX_DUP_PDU_CNTR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_PDU_ALLOC_FAIL(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x520B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_PDU_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_NACK_ALLOC_FAIL(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x530B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_NACK_ALLOC_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_DL_HWB_ALLOC_NUM(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x540B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_DL_HWB_ALLOC_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_START(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x550B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_END(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x560B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define ERLC_LOG_RX_DATA_LOSS_TMOUT(v1) do {\
		if(ERLCDL_Trace_Filter[0]==1 && (ERLCDL_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x570B | ((short)(v1) << 16));\
	} while(0)
#else
	#define ERLC_LOG_RX_DATA_LOSS_TMOUT(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char ERLCDL_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_ERLC_LOG_PDU_BUF_USAGE(short v1, long v2);
void L1TRC_Send_ERLC_LOG_VR_R_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_MS_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_X_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_H_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_UR_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_UX_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_VR_UH_UPDATE(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_T_REORDER_START(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_START_TICK(short v1, long v2);
void L1TRC_Send_ERLC_LOG_T_REORDER_STOP(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY_FAKE(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_EXPRY_MULTI(short v1);
void L1TRC_Send_ERLC_LOG_RX_HT(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RX_MOT(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RX_POLL(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RX_UNKNOWN_PDU(short v1);
void L1TRC_Send_ERLC_LOG_RX_UM5_PDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_RX_UM10_PDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_RX_AM_OOW_PDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RX_AMD_PDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_RX_AMD_SEG(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_RX_AMD_SEG_LSF(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_POLL_BY_DUP_PDU(short v1);
void L1TRC_Send_ERLC_LOG_POLL_BY_PDU(short v1);
void L1TRC_Send_ERLC_LOG_DUP_PDU(short v1);
void L1TRC_Send_ERLC_LOG_DUP_SEG(short v1);
void L1TRC_Send_ERLC_LOG_RX_UM_PDU_DRP_N(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_CHK_CMPLT_OK(short v1);
void L1TRC_Send_ERLC_LOG_CHK_CMPLT_NG(short v1);
void L1TRC_Send_ERLC_LOG_INVALID_R1(short v1);
void L1TRC_Send_ERLC_LOG_INVALID_E_LI(short v1);
void L1TRC_Send_ERLC_LOG_INVALID_LI(short v1);
void L1TRC_Send_ERLC_LOG_INVALID_PDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_LI_VALUE(short v1);
void L1TRC_Send_ERLC_LOG_FI_WO_LI(short v1);
void L1TRC_Send_ERLC_LOG_FI_LI_INFO(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_GEN_STUS_PDU(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DELAY_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_FORCE_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_DL_SEG_STUS_PDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_INVALID_NACK(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_NACK_SN(short v1);
void L1TRC_Send_ERLC_LOG_NACK_SO(short v1, long v2);
void L1TRC_Send_ERLC_LOG_RX_STUS_PDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_INVALID_CPT(short v1);
void L1TRC_Send_ERLC_LOG_INVALID_STUS_PDU(short v1);
void L1TRC_Send_ERLC_LOG_REASM_AM(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_REASM_UM(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_SRB_REASM_N_SDU(short v1, long v2);
void L1TRC_Send_ERLC_LOG_REASM_ONE_SRB(short v1);
void L1TRC_Send_ERLC_LOG_REASM_UM_INVALID_SDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_REASM_UM_INVALID_FI(short v1);
void L1TRC_Send_ERLC_LOG_REASM_AM_INVALID_SDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_REASM_AM_INVALID_FI(short v1);
void L1TRC_Send_ERLC_LOG_REASM_INVALID_SDU_SZ(short v1);
void L1TRC_Send_ERLC_LOG_REASM_SKIP_INVALID_PDU(short v1);
void L1TRC_Send_ERLC_LOG_REASM_SKIP_INVALID_SN(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_CACHE(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_OOW(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_INVALID(short v1, long v2, long v3, long v4);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDPC_SN_VOLTE_OFF(short v1);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CTRL(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DL_RST_COPRO_IDX(short v1);
void L1TRC_Send_ERLC_LOG_DL_POLL_IN_COPRO_OFF(short v1);
void L1TRC_Send_ERLC_LOG_T_REORDER_ZERO(short v1);
void L1TRC_Send_ERLC_LOG_DL_ADD_SRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_ADD_DRB_1(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_ADD_DRB_2(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DL_DEL_SRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_DEL_DRB(short v1, long v2);
void L1TRC_Send_ERLC_LOG_DL_DEL_OLD_DRB(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DL_DEL_NEW_DRB(short v1, long v2, long v3);
void L1TRC_Send_ERLC_LOG_DL_RECFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_DL_REEST_WI_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_DL_REEST_WO_CFG_RB(short v1);
void L1TRC_Send_ERLC_LOG_DL_RB_PARAM_ERR(short v1);
void L1TRC_Send_ERLC_LOG_DL_RB_STUS_ERR(short v1);
void L1TRC_Send_ERLC_LOG_MAX_DUP_PDU_CNTR(short v1, long v2);
void L1TRC_Send_ERLC_LOG_PDU_ALLOC_FAIL(short v1);
void L1TRC_Send_ERLC_LOG_NACK_ALLOC_FAIL(short v1);
void L1TRC_Send_ERLC_LOG_DL_HWB_ALLOC_NUM(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_START(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_END(short v1);
void L1TRC_Send_ERLC_LOG_RX_DATA_LOSS_TMOUT(short v1);

void Set_ERLCDL_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_ERLCDL()	(ERLCDL_Trace_Filter[0]==1)
#define ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()	(ChkL1ModFltr_ERLCDL()&&((ERLCDL_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()	(ChkL1ModFltr_ERLCDL()&&((ERLCDL_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_ERLC_LOG_PDU_BUF_USAGE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_R_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_MS_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_X_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_H_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_UR_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_UX_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_VR_UH_UPDATE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_START()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_START_TICK()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_STOP()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY_FAKE()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_EXPRY_MULTI()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_HT()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_MOT()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_POLL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UNKNOWN_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM5_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM10_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AM_OOW_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AMD_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AMD_SEG()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_AMD_SEG_LSF()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_BY_DUP_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_POLL_BY_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DUP_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DUP_SEG()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_UM_PDU_DRP_N()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_CHK_CMPLT_OK()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_CHK_CMPLT_NG()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_R1()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_E_LI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_LI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_PDU_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_LI_VALUE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FI_WO_LI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_FI_LI_INFO()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_GEN_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DELAY_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_FORCE_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_SEG_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_NACK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_SN()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_NACK_SO()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_CPT()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_INVALID_STUS_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_AM()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_REASM_UM()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_SRB_REASM_N_SDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_REASM_ONE_SRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_REASM_UM_INVALID_SDU_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_UM_INVALID_FI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_AM_INVALID_SDU_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_AM_INVALID_FI()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_INVALID_SDU_SZ()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_SKIP_INVALID_PDU()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_REASM_SKIP_INVALID_SN()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_CHK_OK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_CACHE()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_OOW()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_INVALID()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDPC_SN_VOLTE_OFF()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CTRL()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_UM5_PDCP_SN_SKIP_CHK()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_DL_RST_COPRO_IDX()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_POLL_IN_COPRO_OFF()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_T_REORDER_ZERO()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_SRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_DRB_1()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_ADD_DRB_2()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_SRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_OLD_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_DEL_NEW_DRB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RECFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_REEST_WI_CFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_REEST_WO_CFG_RB()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RB_PARAM_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_RB_STUS_ERR()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_MAX_DUP_PDU_CNTR()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_PDU_ALLOC_FAIL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_NACK_ALLOC_FAIL()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_DL_HWB_ALLOC_NUM()	ChkL1ClsFltr_ERLCDL_ERLCDL_DUMP()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_START()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_END()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()
#define ChkL1MsgFltr_ERLC_LOG_RX_DATA_LOSS_TMOUT()	ChkL1ClsFltr_ERLCDL_ERLCDL_INFO()


#endif
