#ifndef L1TRC_EMAC_DEF_H
#define L1TRC_EMAC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DUMMY(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x000D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DUMMY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MAC_RESET(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x010D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MAC_RESET(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RESET_HW(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x020D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RESET_HW(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_EMAC_STATUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x030D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_EMAC_STATUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_COM_INIT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x040D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_COM_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CH_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x050D | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CH_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_FIRST_MIB_VALID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x060D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_FIRST_MIB_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_RRC(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x070D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_RRC(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_STATUSBITMAP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x080D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_STATUSBITMAP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_CLOSE_RB(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x090D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_CLOSE_RB(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_OPEN_RB(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0A0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_OPEN_RB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_OPEN_RB2(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x0B0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_OPEN_RB2(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_RA(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0C0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_RA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DED_RA(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DED_RA(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_TTI_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x0E0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_TTI_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SCH(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0F0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SCH(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x100D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX2(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x110D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX2(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SHORT_DRX(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x120D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SHORT_DRX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SHORT_DRX_NO_SLP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x130D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SHORT_DRX_NO_SLP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DRX_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x140D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DRX_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_PHR(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x150D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_PHR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_NO_PHR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x160D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_NO_PHR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_PHY(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x170D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_CFG_PHY(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_SR(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x180D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_SR(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_UL_SPS_ENABLE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x190D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_UL_SPS_ENABLE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_UL_SPS_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1A0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_UL_SPS_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DL_SPS_ENABLE(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x1B0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DL_SPS_ENABLE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_DL_SPS_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x1C0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CFG_DL_SPS_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CFG_HARQ_NB(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CFG_HARQ_NB(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SET_EL1_MSG_STATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1E0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_SET_EL1_MSG_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_EL1_CLR_MSG_STATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x1F0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_EL1_CLR_MSG_STATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RCV_EL1_MSG_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x200D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RCV_EL1_MSG_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SET_EL1_MSG_WAIT_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x210D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_SET_EL1_MSG_WAIT_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CLR_EL1_MSG_CNF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x220D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_CLR_EL1_MSG_CNF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_RA_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x230D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_RA_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_TC_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x240D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_TC_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_RA_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x250D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_RA_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_TC_DISABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x260D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_TC_DISABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RNTI_C_ENABLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x270D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RNTI_C_ENABLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SEND_RNTI_UPDATE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x280D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SEND_RNTI_UPDATE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_REL_PUCCH_SRS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x290D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_REL_PUCCH_SRS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_REL_ULDL_SPS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2A0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_REL_ULDL_SPS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x2B0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT2(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2C0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT2(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DET_HARQ_INFO(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2D0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_DET_HARQ_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DET_GRANT_INFO(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2E0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_DET_GRANT_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NEWTX_HARQ(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x2F0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_NEWTX_HARQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_HARQ_CLOSE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x300D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_HARQ_CLOSE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_TX_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x310D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_TX_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_TTI_BUNDLING_ID(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x320D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_TTI_BUNDLING_ID(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_REL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x330D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_REL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_ACT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x340D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_ACT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_NEXT_SPS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x350D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_NEXT_SPS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CCCH_MTX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x360D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CCCH_MTX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CCCH_MTX_PADDING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x370D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CCCH_MTX_PADDING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_CE_CANCEL_BSR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x380D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_CE_CANCEL_BSR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_UL_SPS_UNSENT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x390D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_UL_SPS_UNSENT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_UL_SPS_IMP_RELEASE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3A0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_UL_SPS_IMP_RELEASE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_HARQ_TX_MAX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3B0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_HARQ_TX_MAX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RCV_INVALID_PHICH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3C0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RCV_INVALID_PHICH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RCV_PHICH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x3D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RCV_PHICH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_FORCE_CLOSE_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3E0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_FORCE_CLOSE_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RETX_TBS_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x3F0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RETX_TBS_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_NEW_TX_NDI_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x400D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_NEW_TX_NDI_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x410D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_RETX_GRANT_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x420D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SPS_RETX_GRANT_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SPS_COL_TC_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x430D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SPS_COL_TC_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_INVALID_RETX_UL_GRANT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x440D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_INVALID_RETX_UL_GRANT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CQI_COL_BUNDLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x450D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CQI_COL_BUNDLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CQI_WARNING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x460D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_CQI_WARNING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_SPS_REL_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x470D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_SPS_REL_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_COLL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x480D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_COLL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_DROP(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x490D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_DROP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_GRANT_OVERWRITE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4A0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_UL_GRANT_OVERWRITE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TL_HARQ_CLOSE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4B0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TL_HARQ_CLOSE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_COL_TX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4C0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_COL_TX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_COL_PREAMBLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x4D0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_COL_PREAMBLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_HARQ_COL_MSG3(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4E0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_HARQ_COL_MSG3(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_RETX_HARQ_COL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x4F0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_RETX_HARQ_COL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_TTI_NO_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x500D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_TTI_NO_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_MSG3_TTI_HARQ_COL(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x510D | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_TX_MSG3_TTI_HARQ_COL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_DELAY_TTI_HARQ(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x520D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_TX_DELAY_TTI_HARQ(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_BSR_HOLD_BY_HO(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x530D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_BSR_HOLD_BY_HO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_TRIGGER(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x540D | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_PHR_TRIGGER(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_IND(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x550D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_IND(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_IND_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x560D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_IND_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PHR_PER_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x570D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_PHR_PER_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TX_PHR_PRO_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x580D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TX_PHR_PRO_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_VALUE_SET(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x590D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_PHR_VALUE_SET(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PHR_NOT_REPORT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5A0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_PHR_NOT_REPORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_CANCEL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5B0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_CANCEL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_TRIGGER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5C0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_TRIGGER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_TX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_SR_TX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_STOP_BY_RAR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x5E0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_SR_STOP_BY_RAR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_NO_SR_RESOURCE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x5F0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_NO_SR_RESOURCE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_SR_MAX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x600D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_SR_MAX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_RESTART(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x610D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_RESTART(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_SR_START_PROHIBIT_TMR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x620D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_SR_START_PROHIBIT_TMR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_CMD(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x630D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TA_CMD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x640D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x650D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x660D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x670D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TA_NAG_TA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x680D | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TA_NAG_TA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DISCARD_TC_RNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x690D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_DISCARD_TC_RNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_ACT(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6A0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_ACT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_REL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6B0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_REL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_UPDATE(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x6C0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_UPDATE(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6D0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CTRL_DATA(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x6E0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_DL_CTRL_DATA(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DROP_DL_DATA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x6F0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_DROP_DL_DATA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DROP_RAR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x700D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DL_DROP_RAR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_RETX_CNT_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x710D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_RETX_CNT_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DROP_DCI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x720D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_DROP_DCI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INIT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x730D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INIT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MONITOR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x740D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MONITOR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_INA_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x750D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_INA_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_DL_INA_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x760D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_DL_INA_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TIMER_START(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x770D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TIMER_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TIMER_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x780D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TIMER_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x790D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7A0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7B0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INA_TMR_STOP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7C0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INA_TMR_STOP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_TMR_START(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x7D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_TMR_START(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RTT_TMR_STOP(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x7E0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RTT_TMR_STOP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SHORT_TIMER_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x7F0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SHORT_TIMER_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SHORT_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x800D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SHORT_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RETX_TMR_START(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x810D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RETX_TMR_START(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_RETX_TMR_STOP(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x820D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_RETX_TMR_STOP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ON_LENGTH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x830D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ON_LENGTH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SET_CYCLE_TYPE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x840D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SET_CYCLE_TYPE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SLEEP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x850D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SLEEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ORI_WAKE_TIME(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x860D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ORI_WAKE_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_PST_TIME(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x870D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_PST_TIME(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MOD_WAKE_TIME(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x880D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MOD_WAKE_TIME(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_CYCLE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x890D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_CYCLE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_IS_SHORT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8A0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_IS_SHORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NEXT_IS_LONG(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8B0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NEXT_IS_LONG(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CMD(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x8C0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CMD(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CMD_NO_DRX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8D0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CMD_NO_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SET_RA_FLAG(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8E0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SET_RA_FLAG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CLR_RA_FLAG(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x8F0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CLR_RA_FLAG(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_ACTIVE_SATATUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x900D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DRX_ACTIVE_SATATUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_TX_ACTIVE_STATUS(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x910D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_TX_ACTIVE_STATUS(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_NOTSLP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x920D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_NOTSLP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UL_BUF(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x930D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UL_BUF(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_SEND_CYC_NTF(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x940D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_SEND_CYC_NTF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_INVALID_PDCCH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x950D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_INVALID_PDCCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_MIB_VALID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x960D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_MIB_VALID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x970D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x980D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x990D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9A0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_START(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9B0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_START(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_ASSIGN_IN_SLEEP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x9C0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_ASSIGN_IN_SLEEP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_DATA_IN_SLEEP(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9D0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_DATA_IN_SLEEP(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x9E0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_START_SR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x9F0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_START_SR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RA_ONGOING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA00D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RA_ONGOING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_POT_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA10D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_POT_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG_POW_OFFSET_B(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA20D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG_POW_OFFSET_B(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUPB(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xA30D | ((short)(v1) << 16), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUPB(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_SZ(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xA40D | ((unsigned short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_SZ(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_ASSIGN_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA50D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_ASSIGN_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUP_A_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA60D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUP_A_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GROUP_B_RAPID(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xA70D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_GROUP_B_RAPID(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_INFO(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA80D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_INFO(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_TX(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xA90D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_TX(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_STATE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xAA0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_COMP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAB0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_COMP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_WND(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xAC0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_WND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_RCV(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xAD0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_RCV(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_GRANT(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xAE0D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_GRANT(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_OUT_WND(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xAF0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_OUT_WND(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_CNT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB00D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_CNT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_END_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB10D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_END_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_RESTART(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB20D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_RESTART(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RETRY(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB30D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RETRY(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_BACKOFF(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xB40D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_BACKOFF(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UL_CCCH_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB50D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_UL_CCCH_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_TMR_START(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB60D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_TMR_START(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_TMR_EXP(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB70D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_TMR_EXP(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UEID_FAIL(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0xB80D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define EMAC_LOG_RA_UEID_FAIL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CR_FAIL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xB90D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_MATCH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xBA0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_MATCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_MISMATCH(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBB0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_MISMATCH(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBC0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_FLUSH_MSG3_HARQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBD0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_FLUSH_MSG3_HARQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TC_CR_FAIL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBE0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TC_CR_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TC_CR_SUCCESS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xBF0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TC_CR_SUCCESS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RCV_PDCCH(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC00D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RCV_PDCCH(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CHK_DL_CTRL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC10D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CHK_DL_CTRL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CE_CR_SUCCESS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC20D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_CE_CR_SUCCESS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RELOAD_MSG3(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC30D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RELOAD_MSG3(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_ABORT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC40D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_ABORT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_DL_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC50D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_DL_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_CFG_RESTART(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC60D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_CFG_RESTART(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_CRNTI_TO_TC(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xC70D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_CRNTI_TO_TC(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_PREAMBLE_COL_TX(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC80D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_PREAMBLE_COL_TX(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_STATE_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xC90D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_STATE_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_MSG3_FLUSH_WARNING(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCA0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_MSG3_FLUSH_WARNING(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PRACH_AF_TX_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCB0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PRACH_AF_TX_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_COL_HO(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCC0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_COL_HO(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_PDCCH_COL_UL(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCD0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_PDCCH_COL_UL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_GAP_WARNING(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xCE0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_GAP_WARNING(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MSG3_FORCE_CLOSE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xCF0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_MSG3_FORCE_CLOSE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SAME_TC_RNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD00D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_SAME_TC_RNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_DL_WARNING(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD10D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_DL_WARNING(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_TC_RNTI_DL_AS_CRNTI(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD20D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_TC_RNTI_DL_AS_CRNTI(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_TCRNTI_DATA_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD30D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_DL_TCRNTI_DATA_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD40D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RA_ERROR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD50D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_RA_ERROR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_UL_CRNTI_CHK_SUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD60D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_UL_CRNTI_CHK_SUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xD70D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_DL_RNTI_CHK_SUS(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xD80D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_DL_RNTI_CHK_SUS(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SAVE_MSG3_BUFF(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xD90D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_SAVE_MSG3_BUFF(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xDA0D | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xDB0D | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_TIMEOUT(v1, v2, v3, v4) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xDC0D | ((short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)((char)(v3))) << 8) | (((kal_uint32)((char)(v4))) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_TIMEOUT(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_STOP_CR_TIMER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDD0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_STOP_CR_TIMER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xDE0D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_SMALL_RAR_GRANT(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xDF0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RA_SMALL_RAR_GRANT(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_LMAC_ERR_0(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE00D | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_LMAC_ERR_0(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_LMAC_ERR_1(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE10D | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DL_LMAC_ERR_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_LMAC_ERR_0(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE20D | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_UL_LMAC_ERR_0(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_UL_LMAC_ERR_1(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE30D | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_UL_LMAC_ERR_1(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_MAC_CE_LEN_ERROR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE40D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_MAC_CE_LEN_ERROR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DRX_START_PAST_ON(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xE50D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_DRX_START_PAST_ON(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_RECV_TDM_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xE60D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_RECV_TDM_REQ(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_SUSPEND_ALL_DRB(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xE70D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_SUSPEND_ALL_DRB(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_LEAVE_TDM(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xE80D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_LEAVE_TDM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xE90D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_IGNORE_TDM_HO_RA(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEA0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_IGNORE_TDM_HO_RA(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_STOP_SR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEB0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_STOP_SR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEC0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xED0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_FORCE_LEAVE_TDM(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xEE0D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_FORCE_LEAVE_TDM(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_CANCEL_BSR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xEF0D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v2)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24));\
	} while(0)
#else
	#define EMAC_LOG_IDC_CANCEL_BSR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_ERR_RA_GROUP_A_ERR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF00D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_ERR_RA_GROUP_A_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF10D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_SPS_IN_DRX(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF20D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_SPS_IN_DRX(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_ERR_SPS_GRANT_ERR(v1, v2) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0xF30D | ((unsigned short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_ERR_SPS_GRANT_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_LEN_ERR(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF40D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_LEN_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_DL_CCCH_NO_GPD(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF50D | ((short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_DL_CCCH_NO_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RX_NO_SRB_GPD(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF60D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_RX_NO_SRB_GPD(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_RA_RAR_GRANT_INCONSIST(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xF70D | ((unsigned short)(v1) << 16), (kal_uint32)((char)(v3)) | (((kal_uint32)TRC_L2_PAD) << 8) | (((kal_uint32)TRC_L2_PAD) << 16) | (((kal_uint32)TRC_L2_PAD) << 24), (unsigned long)(v2));\
	} while(0)
#else
	#define EMAC_LOG_RA_RAR_GRANT_INCONSIST(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_PUSCH_TX_REQ(v1, v2, v3) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0xF80D | ((unsigned short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define EMAC_LOG_IDC_PUSCH_TX_REQ(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EMAC_LOG_IDC_NULL_TX_REQ(v1) do {\
		if(EMAC_Trace_Filter[0]==1 && (EMAC_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0xF90D | ((unsigned short)(v1) << 16));\
	} while(0)
#else
	#define EMAC_LOG_IDC_NULL_TX_REQ(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EMAC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EMAC_LOG_DUMMY(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_MAC_RESET(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RESET_HW(unsigned short v1);
void L1TRC_Send_EMAC_LOG_EMAC_STATUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_COM_INIT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CH_MODE(short v1, char v2);
void L1TRC_Send_EMAC_LOG_FIRST_MIB_VALID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_RRC(unsigned short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_STATUSBITMAP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_CLOSE_RB(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_OPEN_RB(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_OPEN_RB2(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_RA(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_DED_RA(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CFG_TTI_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_SCH(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_DRX(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_DRX2(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_SHORT_DRX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_SHORT_DRX_NO_SLP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_DRX_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_PHR(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_NO_PHR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_PHY(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_CFG_SR(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_UL_SPS_ENABLE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_CFG_UL_SPS_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_DL_SPS_ENABLE(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_CFG_DL_SPS_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CFG_HARQ_NB(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SET_EL1_MSG_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_EL1_CLR_MSG_STATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RCV_EL1_MSG_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_SET_EL1_MSG_WAIT_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_CLR_EL1_MSG_CNF(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RNTI_RA_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_TC_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_RA_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_TC_DISABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RNTI_C_ENABLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SEND_RNTI_UPDATE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_REL_PUCCH_SRS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_REL_ULDL_SPS(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT2(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_DET_HARQ_INFO(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_DET_GRANT_INFO(unsigned short v1, char v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_TX_NEWTX_HARQ(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_HARQ_CLOSE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_TX_MODE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_TX_TTI_BUNDLING_ID(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_SPS_REL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_SPS_ACT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_NEXT_SPS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CCCH_MTX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CCCH_MTX_PADDING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_CE_CANCEL_BSR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_UL_SPS_UNSENT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_UL_SPS_IMP_RELEASE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_HARQ_TX_MAX(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RCV_INVALID_PHICH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RCV_PHICH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_FORCE_CLOSE_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RETX_TBS_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_NEW_TX_NDI_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TC_RNTI_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SPS_RETX_GRANT_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SPS_COL_TC_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_INVALID_RETX_UL_GRANT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CQI_COL_BUNDLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_CQI_WARNING(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_SPS_REL_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_UL_GRANT_COLL(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT_DROP(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_UL_GRANT_OVERWRITE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TL_HARQ_CLOSE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_COL_TX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_COL_PREAMBLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_RETX_HARQ_COL_MSG3(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_RETX_HARQ_COL(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_TX_TTI_NO_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_MSG3_TTI_HARQ_COL(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_TX_DELAY_TTI_HARQ(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_BSR_HOLD_BY_HO(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PHR_TRIGGER(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_IND(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_IND_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_PHR_PER_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TX_PHR_PRO_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PHR_VALUE_SET(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_PHR_NOT_REPORT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_CANCEL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_TRIGGER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_TX(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SR_STOP_BY_RAR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_SR_NO_SR_RESOURCE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_SR_MAX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_RESTART(unsigned short v1);
void L1TRC_Send_EMAC_LOG_SR_START_PROHIBIT_TMR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_CMD(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_TA_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TA_NAG_TA(short v1);
void L1TRC_Send_EMAC_LOG_DL_DISCARD_TC_RNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_SPS_ACT(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_SPS_REL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_SPS_UPDATE(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DL_SPS_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_CTRL_DATA(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_DROP_DL_DATA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_DROP_RAR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DL_RETX_CNT_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_DROP_DCI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INIT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_MONITOR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_UL_INA_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_DL_INA_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ON_TIMER_START(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_ON_TIMER_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ON_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_INA_TMR_STOP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_RTT_TMR_START(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_RTT_TMR_STOP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_SHORT_TIMER_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SHORT_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_RETX_TMR_START(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_RETX_TMR_STOP(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_ON_LENGTH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_SET_CYCLE_TYPE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DRX_SLEEP(unsigned short v1, char v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_ORI_WAKE_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_PST_TIME(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_MOD_WAKE_TIME(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_CYCLE(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_IS_SHORT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_NEXT_IS_LONG(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_CMD(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_CMD_NO_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SET_RA_FLAG(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_CLR_RA_FLAG(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_ACTIVE_SATATUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DRX_TX_ACTIVE_STATUS(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_DRX_NOTSLP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_UL_BUF(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_SEND_CYC_NTF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DRX_INVALID_PDCCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_MIB_VALID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_START(unsigned short v1, char v2, char v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_DL_ASSIGN_IN_SLEEP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_DATA_IN_SLEEP(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_PDCCH(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_START_SR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RA_ONGOING(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_POT_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_MSG_POW_OFFSET_B(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUPB(short v1, long v2, long v3, long v4);
void L1TRC_Send_EMAC_LOG_RA_MSG3_SZ(unsigned short v1, long v2);
void L1TRC_Send_EMAC_LOG_RA_ASSIGN_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUP_A_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GROUP_B_RAPID(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PRACH_INFO(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_PRACH_TX(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_STATE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_COMP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_WND(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_RCV(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_RA_RAR_GRANT(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_OUT_WND(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_CNT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_END_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_RESTART(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RETRY(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_BACKOFF(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_UL_CCCH_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CR_TMR_START(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CR_TMR_EXP(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_UEID_FAIL(unsigned short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_EMAC_LOG_RA_CR_FAIL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_MATCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_MISMATCH(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_MSG3_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_FLUSH_MSG3_HARQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TC_CR_FAIL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TC_CR_SUCCESS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RCV_PDCCH(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_CHK_DL_CTRL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_CE_CR_SUCCESS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RELOAD_MSG3(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_ABORT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_DL_ERROR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_CFG_RESTART(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_CRNTI_TO_TC(unsigned short v1);
void L1TRC_Send_EMAC_LOG_PREAMBLE_COL_TX(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_STATE_ERROR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_MSG3_FLUSH_WARNING(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PRACH_AF_TX_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_COL_HO(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_PDCCH_COL_UL(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_GAP_WARNING(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_MSG3_FORCE_CLOSE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_SAME_TC_RNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_TC_RNTI_DL_WARNING(unsigned short v1, char v2, char v3);
void L1TRC_Send_EMAC_LOG_TC_RNTI_DL_AS_CRNTI(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_TCRNTI_DATA_ERROR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_DL_CCCH_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RA_ERROR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_UL_CRNTI_CHK_SUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_DL_RNTI_CHK_SUS(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_SAVE_MSG3_BUFF(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE(short v1, char v2);
void L1TRC_Send_EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_RA_TA_TIMEOUT(short v1, char v2, char v3, char v4);
void L1TRC_Send_EMAC_LOG_RA_TA_STOP_CR_TIMER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RA_SMALL_RAR_GRANT(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_LMAC_ERR_0(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_DL_LMAC_ERR_1(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_UL_LMAC_ERR_0(short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_UL_LMAC_ERR_1(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_MAC_CE_LEN_ERROR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DRX_START_PAST_ON(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_IDC_RECV_TDM_REQ(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_SUSPEND_ALL_DRB(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_LEAVE_TDM(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_IGNORE_TDM_CH_MODE(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_IDC_IGNORE_TDM_HO_RA(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_STOP_SR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_CANCEL_BSR_TRIGGER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_STOP_RETX_BSR_TIMER(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_FORCE_LEAVE_TDM(unsigned short v1);
void L1TRC_Send_EMAC_LOG_IDC_CANCEL_BSR(unsigned short v1, char v2);
void L1TRC_Send_EMAC_LOG_ERR_RA_GROUP_A_ERR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_RCV_UEID_IN_WRONG_TYPE(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_SPS_IN_DRX(unsigned short v1);
void L1TRC_Send_EMAC_LOG_ERR_SPS_GRANT_ERR(unsigned short v1, unsigned long v2);
void L1TRC_Send_EMAC_LOG_DL_CCCH_LEN_ERR(unsigned short v1);
void L1TRC_Send_EMAC_LOG_DL_CCCH_NO_GPD(short v1);
void L1TRC_Send_EMAC_LOG_RX_NO_SRB_GPD(unsigned short v1);
void L1TRC_Send_EMAC_LOG_RA_RAR_GRANT_INCONSIST(unsigned short v1, unsigned long v2, char v3);
void L1TRC_Send_EMAC_LOG_IDC_PUSCH_TX_REQ(unsigned short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_EMAC_LOG_IDC_NULL_TX_REQ(unsigned short v1);

void Set_EMAC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EMAC()	(EMAC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EMAC_EMAC_INFO()	(ChkL1ModFltr_EMAC()&&((EMAC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EMAC_EMAC_DUMP()	(ChkL1ModFltr_EMAC()&&((EMAC_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_EMAC_LOG_DUMMY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MAC_RESET()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RESET_HW()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_EMAC_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_COM_INIT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CH_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_FIRST_MIB_VALID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_RRC()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_STATUSBITMAP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_CLOSE_RB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_OPEN_RB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_OPEN_RB2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DED_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_TTI_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SHORT_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SHORT_DRX_NO_SLP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DRX_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_PHR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_NO_PHR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_PHY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_UL_SPS_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_UL_SPS_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DL_SPS_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_DL_SPS_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CFG_HARQ_NB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SET_EL1_MSG_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_EL1_CLR_MSG_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RCV_EL1_MSG_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SET_EL1_MSG_WAIT_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CLR_EL1_MSG_CNF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_RA_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_TC_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_RA_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_TC_DISABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RNTI_C_ENABLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SEND_RNTI_UPDATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_REL_PUCCH_SRS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_REL_ULDL_SPS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT2()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DET_HARQ_INFO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DET_GRANT_INFO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NEWTX_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_HARQ_CLOSE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_TX_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_TTI_BUNDLING_ID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_REL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_ACT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_NEXT_SPS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CCCH_MTX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CCCH_MTX_PADDING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_CE_CANCEL_BSR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_UL_SPS_UNSENT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_UL_SPS_IMP_RELEASE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_HARQ_TX_MAX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RCV_INVALID_PHICH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RCV_PHICH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_FORCE_CLOSE_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RETX_TBS_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_NEW_TX_NDI_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_RETX_GRANT_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SPS_COL_TC_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_INVALID_RETX_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CQI_COL_BUNDLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CQI_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_SPS_REL_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_COLL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_DROP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_GRANT_OVERWRITE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TL_HARQ_CLOSE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_COL_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_COL_PREAMBLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_HARQ_COL_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_RETX_HARQ_COL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_TTI_NO_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_MSG3_TTI_HARQ_COL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_DELAY_TTI_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_BSR_HOLD_BY_HO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_IND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_IND_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PHR_PER_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TX_PHR_PRO_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_VALUE_SET()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PHR_NOT_REPORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_CANCEL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_STOP_BY_RAR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_NO_SR_RESOURCE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_SR_MAX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_SR_START_PROHIBIT_TMR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_CMD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TA_NAG_TA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DISCARD_TC_RNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_ACT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_REL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_UPDATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CTRL_DATA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DROP_DL_DATA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DROP_RAR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_RETX_CNT_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DROP_DCI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INIT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MONITOR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_INA_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_DL_INA_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TIMER_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INA_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RTT_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SHORT_TIMER_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SHORT_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RETX_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_RETX_TMR_STOP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ON_LENGTH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SET_CYCLE_TYPE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ORI_WAKE_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_PST_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MOD_WAKE_TIME()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_CYCLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_IS_SHORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NEXT_IS_LONG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CMD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CMD_NO_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SET_RA_FLAG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CLR_RA_FLAG()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_ACTIVE_SATATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_TX_ACTIVE_STATUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_NOTSLP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UL_BUF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_SEND_CYC_NTF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_INVALID_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_MIB_VALID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_HOST_DATA_CNF_NOTSLP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_HOST_DATA_CNF_NO_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_CHANGE_TO_LONG_CYCLE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_UPDATE_SRS_CQI_ADMIN()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_ASSIGN_IN_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_DATA_IN_SLEEP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_START_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RA_ONGOING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_POT_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG_POW_OFFSET_B()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUPB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_SZ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_ASSIGN_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUP_A_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GROUP_B_RAPID()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_INFO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_STATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_COMP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_WND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_RCV()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_OUT_WND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_CNT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_END_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RETRY()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_BACKOFF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UL_CCCH_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_TMR_START()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_TMR_EXP()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UEID_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CR_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_MATCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_MISMATCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_FLUSH_MSG3_HARQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TC_CR_FAIL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TC_CR_SUCCESS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RCV_PDCCH()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CHK_DL_CTRL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CE_CR_SUCCESS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RELOAD_MSG3()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_ABORT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_DL_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_CFG_RESTART()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_CRNTI_TO_TC()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_PREAMBLE_COL_TX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_STATE_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_MSG3_FLUSH_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PRACH_AF_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_COL_HO()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_PDCCH_COL_UL()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_GAP_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MSG3_FORCE_CLOSE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SAME_TC_RNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_DL_WARNING()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_TC_RNTI_DL_AS_CRNTI()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_TCRNTI_DATA_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RA_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_UL_CRNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_NEW_UL_CRNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_DL_RNTI_CHK_SUS()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SAVE_MSG3_BUFF()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_INT_IN_WRONG_STATE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_INT_BEROFE_PDCCH_IND()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_TIMEOUT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_STOP_CR_TIMER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_TA_CLR_RAR_UL_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_SMALL_RAR_GRANT()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_LMAC_ERR_0()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_LMAC_ERR_1()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_LMAC_ERR_0()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_UL_LMAC_ERR_1()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_MAC_CE_LEN_ERROR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DRX_START_PAST_ON()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_RECV_TDM_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_SUSPEND_ALL_DRB()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_LEAVE_TDM()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_IGNORE_TDM_CH_MODE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_IGNORE_TDM_HO_RA()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_STOP_SR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_CANCEL_BSR_TRIGGER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_STOP_RETX_BSR_TIMER()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_FORCE_LEAVE_TDM()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_CANCEL_BSR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_ERR_RA_GROUP_A_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RCV_UEID_IN_WRONG_TYPE()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_SPS_IN_DRX()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_ERR_SPS_GRANT_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_LEN_ERR()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_DL_CCCH_NO_GPD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RX_NO_SRB_GPD()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_RA_RAR_GRANT_INCONSIST()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_PUSCH_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()
#define ChkL1MsgFltr_EMAC_LOG_IDC_NULL_TX_REQ()	ChkL1ClsFltr_EMAC_EMAC_INFO()


#endif
