#ifndef L1TRC_EPDCP_DEF_H
#define L1TRC_EPDCP_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_START_POLLING(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x000F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_START_POLLING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_RX_PDU_CNT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x010F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_RX_PDU_CNT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPDT_DL_SRB_SN(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x020F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UPDT_DL_SRB_SN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_DCCH_DATA_IND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x030F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_DCCH_DATA_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_SRB_PDU_INT_ERR(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x040F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_SRB_PDU_INT_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_STATE(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x050F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_INV_ORD_CB_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x060F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_INV_ORD_CB_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x070F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_FLUSH(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x080F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_FLUSH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UTILIZE_TAIL_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x090F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UTILIZE_TAIL_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0A0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESTORE_DL_QMU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x0B0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RESTORE_DL_QMU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PDU_PDCP_COUNT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0C0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PDU_PDCP_COUNT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RSM_CB_CHNL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0D0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RSM_CB_CHNL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DCIP_CB_GPD_BY_SWM(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DCIP_CB_GPD_BY_SWM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPDT_DL_AMDRB_SN(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x0F0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UPDT_DL_AMDRB_SN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_MAKE_SOD_INFO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x100F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_MAKE_SOD_INFO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EXEC_DL_ROHC(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x110F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_EXEC_DL_ROHC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x120F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x130F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NXT_SRB1_DL_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x140F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_NXT_SRB1_DL_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_UM_STATUS_REPORT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x150F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INV_UM_STATUS_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_ROHC_FBK_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x160F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RX_ROHC_FBK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_INVALID_CTRL_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x170F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RX_INVALID_CTRL_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RX_INVALID_R_BIT_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x180F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RX_INVALID_R_BIT_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CRIT_BRK_OCCUR(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x190F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CRIT_BRK_OCCUR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_GATHER_GPD_RESULT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x1A0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_GATHER_GPD_RESULT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CE_OUTPUT_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1B0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_CE_OUTPUT_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INACT_DL_CHNL_FOR_RSM(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1C0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_INACT_DL_CHNL_FOR_RSM(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CHECK_DCIP_RULE_SN(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1D0F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_CHECK_DCIP_RULE_SN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESTORE_AM_DCIP_RULE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1E0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RESTORE_AM_DCIP_RULE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RSM_CB_CHNL_SN(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1F0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RSM_CB_CHNL_SN(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_DL_MACI_CMP(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x200F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_DL_MACI_CMP(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPDT_DL_UMDRB_SN(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x210F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UPDT_DL_UMDRB_SN(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_GET_SWM_RSLT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x220F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_GET_SWM_RSLT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STILL_WAIT_FOR_FLUSH(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x230F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STILL_WAIT_FOR_FLUSH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x240F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x250F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_POLLING_DL_ROHC_RESULT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x260F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_POLLING_DL_ROHC_RESULT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x270F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x280F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEND_LTM_DATA_IND(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_1_word(0x290F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SEND_LTM_DATA_IND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INS_TO_DL_WND(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2A0F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_INS_TO_DL_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_DUPL_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2B0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_DUPL_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_AM_INORDR_DLVR(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_2_word(0x2C0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_AM_INORDR_DLVR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELOAD_DL_GPDS(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2D0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RELOAD_DL_GPDS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x2E0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STATUS_RPRT_WND_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x2F0F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STATUS_RPRT_WND_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_GEN_STATUS_RPRT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x300F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_GEN_STATUS_RPRT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CURR_DL_SN_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x310F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_CURR_DL_SN_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_DROP_PDUS_IN_WND(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x320F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_DROP_PDUS_IN_WND(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_DROP_UM_PDUS(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_4_word(0x330F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_DROP_UM_PDUS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_ENTER(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x340F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_ENTER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_FC_EXIT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x350F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DL_FC_EXIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DL_PDCP_CNT_2_IPID(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x360F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DL_PDCP_CNT_2_IPID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_LB_CFG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x370F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_LB_CFG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_LB_CFG_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x380F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_LB_CFG_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_LB_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x390F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_LB_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_WI_SCALE(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x3A0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_LB_WI_SCALE(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_WO_SCALE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3B0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LB_WO_SCALE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_LB_DISC_PDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3C0F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_LB_DISC_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENABLE_DRB_LB_MODE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3D0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ENABLE_DRB_LB_MODE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_PARAM_CIP(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x3E0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_PARAM_CIP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_PARAM_INT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3F0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_PARAM_INT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_IN_SRB_HW(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x400F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_IN_SRB_HW(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UPD_SEC_IN_DRB_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x410F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UPD_SEC_IN_DRB_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACTIVATE_DL_SEC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x420F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ACTIVATE_DL_SEC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACTIVATE_UL_SEC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x430F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ACTIVATE_UL_SEC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_CNT_INFO_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x440F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_CNT_INFO_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_CNT_INFO_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x450F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_CNT_INFO_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SHOW_DRB_COUNT_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x460F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_SHOW_DRB_COUNT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_CFG_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x470F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_CFG_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_CFG_CNF(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x480F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_CFG_CNF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PROC_CONFIG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x490F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_PROC_CONFIG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EXEC_SAVED_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x4A0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_EXEC_SAVED_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SAVE_CFG_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4B0F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SAVE_CFG_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_CFG_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x4C0F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_CFG_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DEL_RB_HNDLR(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4D0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DEL_RB_HNDLR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DELETE_RB(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x4E0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DELETE_RB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_MODIFY_RB(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x4F0F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_MODIFY_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ESTABLISH_RB(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x500F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ESTABLISH_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_MODE_CHNG(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x510F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_SND_MODE_CHNG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_SRB_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x520F | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_EST_SRB_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESUME_SRB_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x530F | ((short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RESUME_SRB_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x540F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_2(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x550F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_EST_DRB_INFO_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x560F | ((short)(v1) << 16), (kal_uint32)((char)(v4)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_EST_DRB_INFO_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_DRB_INFO_1(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x570F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_DRB_INFO_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_DRB_INFO_2(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x580F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_DRB_INFO_2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ADD_ROHC_CHNL(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x590F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ADD_ROHC_CHNL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DEL_ROHC_CHNL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DEL_ROHC_CHNL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CHNG_ROHC_CHNL(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5B0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CHNG_ROHC_CHNL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_NOT_SUPPORT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x5C0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_NOT_SUPPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x5D0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5E0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_TOGGLE_ACTV_ENT_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_UM_HW_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x5F0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_UM_HW_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x600F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x610F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RELEASE_DRB(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x620F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RELEASE_DRB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_DL_PDUS(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x630F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REL_DL_PDUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REDIR_UL_DATA(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x640F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REDIR_UL_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_IDC_START(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x650F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_IDC_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_IDC_END(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x660F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_IDC_END(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PWRDWN_HW(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x670F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_PWRDWN_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REINIT_HW(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x680F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REINIT_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_SEC_STATE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x690F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INV_SEC_STATE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_FORCE_DISABLE_ROHC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x6A0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_FORCE_DISABLE_ROHC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SND_DCCH_DATA_CNF(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6B0F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SND_DCCH_DATA_CNF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6C0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6D0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6E0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x6F0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_RETX_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x700F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_RETX_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_ROHC_FBK_PDU(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x710F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_REL_ROHC_FBK_PDU(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x720F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNROHC_RSLT_CNT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x730F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UNROHC_RSLT_CNT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_UL_ROHC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x740F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_UL_ROHC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CLEAR_CIP_QUE(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x750F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_CLEAR_CIP_QUE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_CTRL_QUE_SIZE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x760F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_REL_CTRL_QUE_SIZE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_SAVED_PC(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x770F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_SAVED_PC(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WO_SAVED_PC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x780F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WO_SAVED_PC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x790F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7A0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7B0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7C0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x7D0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_NEW_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7E0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_NEW_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RETX_PDU_WI_OLD_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7F0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RETX_PDU_WI_OLD_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_DCCH_DATA(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x800F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_DCCH_DATA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_2_word(0x810F | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_PARTIAL_DATA_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x820F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_PARTIAL_DATA_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_PDCP_DATA_REQ(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0x830F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_PDCP_DATA_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACPT_PDCP_DATA_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_3_word(0x840F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ACPT_PDCP_DATA_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENQ_TO_UL_ROHC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x850F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_ENQ_TO_UL_ROHC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x860F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x870F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_BKT_VACANCY(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x880F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_BKT_VACANCY(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x890F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FORM_DRB_DATA_PDU(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x8A0F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FORM_DRB_DATA_PDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FORM_SRB_DATA_PDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8B0F | ((short)(v1) << 16), (unsigned long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FORM_SRB_DATA_PDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PRETX_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0x8C0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_PRETX_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8D0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x8E0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RCV_UL_ROHC_RSLT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8F0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RCV_UL_ROHC_RSLT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_RETX_PDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x900F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_RETX_PDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_PRI_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x910F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_PRI_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_ROHC_OF_NML_SDU(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x920F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_ROHC_OF_NML_SDU(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SEARCH_TMOUT_SDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x930F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SEARCH_TMOUT_SDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_IN_CIP_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x940F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_IN_CIP_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x950F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x960F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x970F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x980F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_DISC_TMOUT_GPD(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x990F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_DISC_TMOUT_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RESEND_UNTXSCHED_GPDS(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9A0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_RESEND_UNTXSCHED_GPDS(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_CTRL_PDU_INFO(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9B0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_CTRL_PDU_INFO(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9C0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NTMOUT_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9D0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_NTMOUT_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9E0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x9F0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA00F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_RETX_Q_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA10F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_RETX_Q_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_TMOUT_SDU_Q_END(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xA20F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_TMOUT_SDU_Q_END(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_PARAM(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA30F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_PARAM(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INT_PROT_RSLT_MACI(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA40F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_INT_PROT_RSLT_MACI(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_1(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA50F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_1(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA60F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_3(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA70F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_3(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_RB_UL_BKT_INFO_4(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA80F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_RB_UL_BKT_INFO_4(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UMDRB_REL_ULGPD_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0xA90F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UMDRB_REL_ULGPD_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAA0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UNSCHED_CIP_QUE_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAB0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UNSCHED_CIP_QUE_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_AMDRB_ACK_ULGPD_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x02)!=0 )\
			l2trc_send_4_word(0xAC0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_AMDRB_ACK_ULGPD_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAD0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ENABLE_UL_FC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAE0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_ENABLE_UL_FC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISABLE_UL_FC(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAF0F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_DISABLE_UL_FC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_ACPT_DCCH_DATA_REQ(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB00F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_ACPT_DCCH_DATA_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_REL_CPLT_GPD(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB10F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_REL_CPLT_GPD(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_DATA_ACK_HNDLR(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB20F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_DATA_ACK_HNDLR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB30F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB40F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_ACK_ULSDU_START(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xB50F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_ACK_ULSDU_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_SRB_UPD_NXT_REl_SIT(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB60F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_SRB_UPD_NXT_REl_SIT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_PROC_STATUS_REPORT(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xB70F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_PROC_STATUS_REPORT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_RPRT_BITMAP_LONG(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB80F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_RPRT_BITMAP_LONG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xB90F | ((short)(v1) << 16), (long)(v2), (long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_1(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xBA0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_1(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_2(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBB0F | ((short)(v1) << 16), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_3(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xBC0F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_3(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_END(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xBD0F | ((short)(v1) << 16), (long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_STUS_ACK_CIP_QUE_END(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_STOP_DISC_ACKED_GPD(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xBE0F | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_STOP_DISC_ACKED_GPD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_PDU_SIT_AND_SN(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xBF0F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_UL_PDU_SIT_AND_SN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DISC_REQ_TO_RLC(v1, v2) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC00F | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EPDCP_LOG_DISC_REQ_TO_RLC(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INV_FMS_STATUS_REPORT(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xC10F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INV_FMS_STATUS_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_PDCP_CNT_2_IPID(v1, v2, v3) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xC20F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EPDCP_LOG_UL_PDCP_CNT_2_IPID(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_UL_FC_DROP_SDU(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xC30F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_UL_FC_DROP_SDU(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_INJ_CHG_REL_GPD_NUM(v1) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x04)!=0 )\
			l2trc_send_1_word(0xC40F | ((short)(v1) << 16));\
	} while(0)
#else
	#define EPDCP_LOG_INJ_CHG_REL_GPD_NUM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY_SIGNED(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xC50F | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY_SIGNED(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xC60F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPDCP_LOG_DUMMY_HEX(v1, v2, v3, v4) do {\
		if(EPDCP_Trace_Filter[0]==1 && (EPDCP_Trace_Filter[1]&0x08)!=0 )\
			l2trc_send_4_word(0xC70F | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EPDCP_LOG_DUMMY_HEX(v1, v2, v3, v4)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EPDCP_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EPDCP_LOG_START_POLLING(short v1);
void L1TRC_Send_EPDCP_LOG_SRB_RX_PDU_CNT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UPDT_DL_SRB_SN(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_SEND_DCCH_DATA_IND(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DROP_SRB_PDU_INT_ERR(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_STATE(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DROP_INV_ORD_CB_PDU(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_TO_STOP_CHNL(short v1);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_FLUSH(short v1);
void L1TRC_Send_EPDCP_LOG_UTILIZE_TAIL_GPD(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DROP_PDU_BY_TAIL_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_RESTORE_DL_QMU(short v1);
void L1TRC_Send_EPDCP_LOG_DL_PDU_PDCP_COUNT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RSM_CB_CHNL(short v1);
void L1TRC_Send_EPDCP_LOG_DCIP_CB_GPD_BY_SWM(short v1);
void L1TRC_Send_EPDCP_LOG_UPDT_DL_AMDRB_SN(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_MAKE_SOD_INFO(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_EXEC_DL_ROHC(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_HWM_DCIP(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_SWM_DCIP(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_NXT_SRB1_DL_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_INV_UM_STATUS_REPORT(short v1);
void L1TRC_Send_EPDCP_LOG_RX_ROHC_FBK_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_RX_INVALID_CTRL_PDU(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RX_INVALID_R_BIT_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_CRIT_BRK_OCCUR(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_GATHER_GPD_RESULT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_CE_OUTPUT_INFO(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_INACT_DL_CHNL_FOR_RSM(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_CHECK_DCIP_RULE_SN(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_RESTORE_AM_DCIP_RULE(short v1);
void L1TRC_Send_EPDCP_LOG_RSM_CB_CHNL_SN(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_INT_PROT_DL_MACI_CMP(short v1, unsigned long v2, unsigned long v3, long v4);
void L1TRC_Send_EPDCP_LOG_UPDT_DL_UMDRB_SN(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_GET_SWM_RSLT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_STILL_WAIT_FOR_FLUSH(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_DL_FLUSH_FOR_REL_DONE(short v1);
void L1TRC_Send_EPDCP_LOG_POLLING_DL_ROHC_RESULT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_SEND_LTM_DATA_IND(short v1);
void L1TRC_Send_EPDCP_LOG_INS_TO_DL_WND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_REL_DUPL_PDU(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_AM_INORDR_DLVR(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RELOAD_DL_GPDS(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RELOAD_DL_GPDS_IN_HO(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_STATUS_RPRT_WND_INFO(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_GEN_STATUS_RPRT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_CURR_DL_SN_INFO(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DL_FC_DROP_PDUS_IN_WND(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DL_FC_DROP_UM_PDUS(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DL_FC_ENTER(short v1);
void L1TRC_Send_EPDCP_LOG_DL_FC_EXIT(short v1);
void L1TRC_Send_EPDCP_LOG_DL_PDCP_CNT_2_IPID(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_RCV_LB_CFG_REQ(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SND_LB_CFG_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_LB_CFG_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_LB_WI_SCALE(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_LB_WO_SCALE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_LB_DISC_PDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_ENABLE_DRB_LB_MODE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_PARAM_CIP(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_PARAM_INT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_IN_SRB_HW(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UPD_SEC_IN_DRB_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_ACTIVATE_DL_SEC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_ACTIVATE_UL_SEC(short v1);
void L1TRC_Send_EPDCP_LOG_RCV_CNT_INFO_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_SND_CNT_INFO_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_SHOW_DRB_COUNT_INFO(short v1, long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_RCV_CFG_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_SND_CFG_CNF(short v1);
void L1TRC_Send_EPDCP_LOG_PROC_CONFIG_REQ(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_EXEC_SAVED_CFG_REQ(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_SAVE_CFG_REQ(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_CFG_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DEL_RB_HNDLR(short v1);
void L1TRC_Send_EPDCP_LOG_DELETE_RB(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_MODIFY_RB(short v1, char v2, long v3);
void L1TRC_Send_EPDCP_LOG_ESTABLISH_RB(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SND_MODE_CHNG(short v1);
void L1TRC_Send_EPDCP_LOG_EST_SRB_INFO(short v1, unsigned long v2, unsigned long v3, char v4);
void L1TRC_Send_EPDCP_LOG_RESUME_SRB_INFO(short v1, unsigned long v2, char v3);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_2(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_EST_DRB_INFO_3(short v1, unsigned long v2, unsigned long v3, char v4);
void L1TRC_Send_EPDCP_LOG_RECFG_DRB_INFO_1(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RECFG_DRB_INFO_2(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_ADD_ROHC_CHNL(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_DEL_ROHC_CHNL(short v1);
void L1TRC_Send_EPDCP_LOG_CHNG_ROHC_CHNL(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_ROHC_NOT_SUPPORT(short v1);
void L1TRC_Send_EPDCP_LOG_TOGGLE_ACTV_ENT_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_TOGGLE_ACTV_ENT_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_RECFG_UM_HW_CHNL(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RECFG_AM_HW_CIP_CHNL(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RELEASE_DRB(short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_REL_DL_PDUS(short v1);
void L1TRC_Send_EPDCP_LOG_REDIR_UL_DATA(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_IDC_START(short v1);
void L1TRC_Send_EPDCP_LOG_IDC_END(short v1);
void L1TRC_Send_EPDCP_LOG_PWRDWN_HW(short v1);
void L1TRC_Send_EPDCP_LOG_REINIT_HW(short v1);
void L1TRC_Send_EPDCP_LOG_INV_SEC_STATE(short v1);
void L1TRC_Send_EPDCP_LOG_FORCE_DISABLE_ROHC(short v1);
void L1TRC_Send_EPDCP_LOG_SND_DCCH_DATA_CNF(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL(short v1);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_CLEAN_ROHC_QUE_RSLT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UNROHC_RETX_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_REL_ROHC_FBK_PDU(short v1);
void L1TRC_Send_EPDCP_LOG_UNROHC_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UNROHC_RSLT_CNT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STOP_UL_ROHC(short v1);
void L1TRC_Send_EPDCP_LOG_CLEAR_CIP_QUE(short v1);
void L1TRC_Send_EPDCP_LOG_REL_CTRL_QUE_SIZE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_SAVED_PC(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WO_SAVED_PC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBUM_RESUME_TX_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DRBUM_RESUME_TX_INFO_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_2(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRBAM_RESUME_TX_INFO_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_NEW_SN(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RETX_PDU_WI_OLD_SN(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_DCCH_DATA(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ(short v1, char v2);
void L1TRC_Send_EPDCP_LOG_DISC_PARTIAL_DATA_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_DISC_PDCP_DATA_REQ(short v1);
void L1TRC_Send_EPDCP_LOG_ACPT_PDCP_DATA_REQ(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_ENQ_TO_UL_ROHC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_UL_BKT_VACANCY(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UL_FORM_ROHC_FBK_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_FORM_DRB_DATA_PDU(short v1, unsigned long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_UL_FORM_SRB_DATA_PDU(short v1, unsigned long v2, long v3);
void L1TRC_Send_EPDCP_LOG_PRETX_INFO(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_RCV_UL_ROHC_RSLT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_RETX_PDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_PRI_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UL_ROHC_OF_NML_SDU(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_SEARCH_TMOUT_SDU(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_TMOUT_IN_CIP_QUE(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_2(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_CIP_QUE_END(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_STOP_DISC_TMOUT_GPD(short v1);
void L1TRC_Send_EPDCP_LOG_RESEND_UNTXSCHED_GPDS(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_CTRL_PDU_INFO(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_TMOUT_PDU_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_NTMOUT_PDU_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_TMOUT_QUEUED_SDU_INFO(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_RETX_Q_END(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_DISC_TMOUT_SDU_Q_END(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_INT_PROT_PARAM(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_INT_PROT_RSLT_MACI(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_1(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_2(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_3(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_RB_UL_BKT_INFO_4(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UMDRB_REL_ULGPD_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_REL_SCHED_CIP_QUE_GPD(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_UNSCHED_CIP_QUE_GPD(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_AMDRB_ACK_ULGPD_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_REL_ACKED_CIP_QUE_GPD(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_ENABLE_UL_FC(short v1);
void L1TRC_Send_EPDCP_LOG_DISABLE_UL_FC(short v1);
void L1TRC_Send_EPDCP_LOG_ACPT_DCCH_DATA_REQ(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_SRB_REL_CPLT_GPD(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_DATA_ACK_HNDLR(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_SRB_ACK_ULSDU_START(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_SRB_UPD_NXT_REl_SIT(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_PROC_STATUS_REPORT(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STUS_RPRT_BITMAP_LONG(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_STUS_RPRT_REF_FMS_INFO(short v1, long v2, long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_1(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_2(short v1, long v2, long v3);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_3(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_STUS_ACK_CIP_QUE_END(short v1, long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_STOP_DISC_ACKED_GPD(short v1, unsigned long v2);
void L1TRC_Send_EPDCP_LOG_UL_PDU_SIT_AND_SN(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_DISC_REQ_TO_RLC(short v1, long v2);
void L1TRC_Send_EPDCP_LOG_INV_FMS_STATUS_REPORT(short v1);
void L1TRC_Send_EPDCP_LOG_UL_PDCP_CNT_2_IPID(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EPDCP_LOG_UL_FC_DROP_SDU(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_INJ_CHG_REL_GPD_NUM(short v1);
void L1TRC_Send_EPDCP_LOG_DUMMY_SIGNED(short v1, long v2, long v3, long v4);
void L1TRC_Send_EPDCP_LOG_DUMMY(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EPDCP_LOG_DUMMY_HEX(short v1, unsigned long v2, unsigned long v3, unsigned long v4);

void Set_EPDCP_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EPDCP()	(EPDCP_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EPDCP_EPDCP_INFO()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_WARN()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EPDCP_EPDCP_DUMP()	(ChkL1ModFltr_EPDCP()&&((EPDCP_Trace_Filter[1]&0x08)!=0))
#define ChkL1MsgFltr_EPDCP_LOG_START_POLLING()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_RX_PDU_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPDT_DL_SRB_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_DCCH_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_SRB_PDU_INT_ERR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_STATE()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_INV_ORD_CB_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_TO_STOP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_FLUSH()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_UTILIZE_TAIL_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DROP_PDU_BY_TAIL_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RESTORE_DL_QMU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PDU_PDCP_COUNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RSM_CB_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DCIP_CB_GPD_BY_SWM()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPDT_DL_AMDRB_SN()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_MAKE_SOD_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EXEC_DL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_HWM_DCIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_SWM_DCIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NXT_SRB1_DL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_UM_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RX_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RX_INVALID_CTRL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_RX_INVALID_R_BIT_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_CRIT_BRK_OCCUR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_GATHER_GPD_RESULT()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_CE_OUTPUT_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INACT_DL_CHNL_FOR_RSM()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CHECK_DCIP_RULE_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RESTORE_AM_DCIP_RULE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RSM_CB_CHNL_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_DL_MACI_CMP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPDT_DL_UMDRB_SN()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_GET_SWM_RSLT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STILL_WAIT_FOR_FLUSH()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FLUSH_FOR_REEST_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FLUSH_FOR_REL_DONE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_POLLING_DL_ROHC_RESULT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_OOW_PDU_AFTER_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_HAS_DL_DATA_TO_LTM()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_SEND_LTM_DATA_IND()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_INS_TO_DL_WND()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_DUPL_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_AM_INORDR_DLVR()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_RELOAD_DL_GPDS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RELOAD_DL_GPDS_IN_HO()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_STATUS_RPRT_WND_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_GEN_STATUS_RPRT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CURR_DL_SN_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_DROP_PDUS_IN_WND()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_DROP_UM_PDUS()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_ENTER()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_FC_EXIT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DL_PDCP_CNT_2_IPID()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_LB_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_LB_CFG_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_LB_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_LB_WI_SCALE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_LB_WO_SCALE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_LB_DISC_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ENABLE_DRB_LB_MODE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_PARAM_CIP()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_PARAM_INT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_IN_SRB_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UPD_SEC_IN_DRB_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACTIVATE_DL_SEC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACTIVATE_UL_SEC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_CNT_INFO_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_CNT_INFO_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SHOW_DRB_COUNT_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_CFG_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PROC_CONFIG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EXEC_SAVED_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_SAVE_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_CFG_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DEL_RB_HNDLR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DELETE_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_MODIFY_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ESTABLISH_RB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SND_MODE_CHNG()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_SRB_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RESUME_SRB_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_EST_DRB_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_DRB_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_DRB_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ADD_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DEL_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CHNG_ROHC_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_NOT_SUPPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_TOGGLE_ACTV_ENT_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TOGGLE_ACTV_ENT_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_UM_HW_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_AM_HW_CIP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RECFG_AM_HW_DCIP_CHNL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RELEASE_DRB()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_DL_PDUS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REDIR_UL_DATA()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_IDC_START()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_IDC_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PWRDWN_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REINIT_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_SEC_STATE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_FORCE_DISABLE_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_SND_DCCH_DATA_CNF()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_ACK_TBL()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CFN_DISC_MSG_IN_SDU_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CLEAN_ROHC_QUE_RSLT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_RETX_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNROHC_RSLT_CNT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_UL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CLEAR_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_REL_CTRL_QUE_SIZE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_SAVED_PC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WO_SAVED_PC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBUM_RESUME_TX_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBUM_RESUME_TX_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRBAM_RESUME_TX_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_NEW_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RETX_PDU_WI_OLD_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_DCCH_DATA()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_WRONG_IN_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_PARTIAL_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_ACPT_PDCP_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_ENQ_TO_UL_ROHC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DRB_ENQ_TO_UL_CIP_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ENQ_TO_UL_CIP_HW()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_BKT_VACANCY()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FORM_ROHC_FBK_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FORM_DRB_DATA_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FORM_SRB_DATA_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PRETX_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_FBK_ENQ_NML_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ROHC_FBK_ENQ_CTRL_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RCV_UL_ROHC_RSLT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_RETX_PDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_PRI_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_ROHC_OF_NML_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SEARCH_TMOUT_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_IN_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_CIP_QUE_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_DISC_TMOUT_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RESEND_UNTXSCHED_GPDS()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_CTRL_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NTMOUT_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_RETX_Q_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_NTMOUT_RETX_Q_PDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_TMOUT_QUEUED_SDU_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_RETX_Q_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_TMOUT_SDU_Q_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_PARAM()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INT_PROT_RSLT_MACI()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_RB_UL_BKT_INFO_4()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UMDRB_REL_ULGPD_START()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_REL_SCHED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UNSCHED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_AMDRB_ACK_ULGPD_START()	ChkL1ClsFltr_EPDCP_EPDCP_NTPUT()
#define ChkL1MsgFltr_EPDCP_LOG_REL_ACKED_CIP_QUE_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ENABLE_UL_FC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISABLE_UL_FC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_ACPT_DCCH_DATA_REQ()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_REL_CPLT_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_DATA_ACK_HNDLR()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU_CIP_QUE()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_ACK_ULSDU_START()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_SRB_UPD_NXT_REl_SIT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_PROC_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_RPRT_BITMAP_LONG()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_RPRT_REF_FMS_INFO()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_1()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_2()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_3()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STUS_ACK_CIP_QUE_END()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_STOP_DISC_ACKED_GPD()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_PDU_SIT_AND_SN()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_DISC_REQ_TO_RLC()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INV_FMS_STATUS_REPORT()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_UL_PDCP_CNT_2_IPID()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_UL_FC_DROP_SDU()	ChkL1ClsFltr_EPDCP_EPDCP_INFO()
#define ChkL1MsgFltr_EPDCP_LOG_INJ_CHG_REL_GPD_NUM()	ChkL1ClsFltr_EPDCP_EPDCP_WARN()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY_SIGNED()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()
#define ChkL1MsgFltr_EPDCP_LOG_DUMMY_HEX()	ChkL1ClsFltr_EPDCP_EPDCP_DUMP()


#endif
