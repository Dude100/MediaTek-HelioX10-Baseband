#ifndef L1TRC_L2_LTE_COPRO_DRV_DEF_H
#define L1TRC_L2_LTE_COPRO_DRV_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_DRV_WARN(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x002B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_DRV_WARN(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_DRV_INFO(v1, v2, v3, v4) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x012B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L2_DRV_INFO(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_DRV_ERR_3(v1, v2, v3) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x022B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L2_DRV_ERR_3(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_DRV_ERR_4(v1, v2, v3, v4) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x032B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L2_DRV_ERR_4(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_SHOW_ERR_REG(v1, v2, v3) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_3_word(0x042B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define L2_SHOW_ERR_REG(v1, v2, v3)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_EVT_NOT_SUPPORT(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x052B | ((short)(v1) << 16), (long)(v2));\
	} while(0)
#else
	#define L2_EVT_NOT_SUPPORT(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_INIT_FAIL(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x062B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_LMAC_INIT_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_RAR_CB_FAIL(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x072B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_LMAC_RAR_CB_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_EAR_CB_FAIL(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x082B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_LMAC_EAR_CB_FAIL(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_UL_EVT_CB_FAIL(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x092B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define L2_LMAC_UL_EVT_CB_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_DL_EVT_CB_FAIL(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0A2B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define L2_LMAC_DL_EVT_CB_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_UL_ERR_CB_FAIL(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0B2B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define L2_LMAC_UL_ERR_CB_FAIL(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_DL_ERR_CB_FAIL(v1, v2, v3, v4) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0C2B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L2_LMAC_DL_ERR_CB_FAIL(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_UL_ERR(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0D2B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define L2_LMAC_UL_ERR(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_DL_ERR(v1, v2, v3, v4) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_4_word(0x0E2B | ((short)(v1) << 16), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define L2_LMAC_DL_ERR(v1, v2, v3, v4)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_DL_ERR3_DUMP(v1, v2) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_2_word(0x0F2B | ((short)(v1) << 16), (unsigned long)(v2));\
	} while(0)
#else
	#define L2_LMAC_DL_ERR3_DUMP(v1, v2)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_GENERAL_ERR(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x102B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_LMAC_GENERAL_ERR(v1)
#endif

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define L2_LMAC_UL_UNDERRUN_WARN(v1) do {\
		if(L2_LTE_COPRO_DRV_Trace_Filter[0]==1 && (L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0 )\
			l2trc_send_1_word(0x112B | ((short)(v1) << 16));\
	} while(0)
#else
	#define L2_LMAC_UL_UNDERRUN_WARN(v1)
#endif



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char L2_LTE_COPRO_DRV_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_L2_DRV_WARN(short v1);
void L1TRC_Send_L2_DRV_INFO(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L2_DRV_ERR_3(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L2_DRV_ERR_4(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L2_SHOW_ERR_REG(short v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_L2_EVT_NOT_SUPPORT(short v1, long v2);
void L1TRC_Send_L2_LMAC_INIT_FAIL(short v1);
void L1TRC_Send_L2_LMAC_RAR_CB_FAIL(short v1);
void L1TRC_Send_L2_LMAC_EAR_CB_FAIL(short v1);
void L1TRC_Send_L2_LMAC_UL_EVT_CB_FAIL(short v1, unsigned long v2);
void L1TRC_Send_L2_LMAC_DL_EVT_CB_FAIL(short v1, unsigned long v2);
void L1TRC_Send_L2_LMAC_UL_ERR_CB_FAIL(short v1, unsigned long v2);
void L1TRC_Send_L2_LMAC_DL_ERR_CB_FAIL(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L2_LMAC_UL_ERR(short v1, unsigned long v2);
void L1TRC_Send_L2_LMAC_DL_ERR(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_L2_LMAC_DL_ERR3_DUMP(short v1, unsigned long v2);
void L1TRC_Send_L2_LMAC_GENERAL_ERR(short v1);
void L1TRC_Send_L2_LMAC_UL_UNDERRUN_WARN(short v1);

void Set_L2_LTE_COPRO_DRV_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_L2_LTE_COPRO_DRV()	(L2_LTE_COPRO_DRV_Trace_Filter[0]==1)
#define ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()	(ChkL1ModFltr_L2_LTE_COPRO_DRV()&&((L2_LTE_COPRO_DRV_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_L2_LTE_COPRO_DRV_Others()	(ChkL1ModFltr_L2_LTE_COPRO_DRV()&&((L2_LTE_COPRO_DRV_Trace_Filter[1]&0x02)!=0))
#define ChkL1MsgFltr_L2_DRV_WARN()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_DRV_INFO()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_DRV_ERR_3()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_DRV_ERR_4()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_SHOW_ERR_REG()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_EVT_NOT_SUPPORT()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_INIT_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_RAR_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_EAR_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_UL_EVT_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_DL_EVT_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_UL_ERR_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_DL_ERR_CB_FAIL()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_UL_ERR()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_DL_ERR()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_DL_ERR3_DUMP()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_GENERAL_ERR()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()
#define ChkL1MsgFltr_L2_LMAC_UL_UNDERRUN_WARN()	ChkL1ClsFltr_L2_LTE_COPRO_DRV_L2_LOG()


#endif
