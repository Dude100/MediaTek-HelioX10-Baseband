#ifndef L1TRC_EPHY_RF_DEF_H
#define L1TRC_EPHY_RF_DEF_H

/******************************/
/* String category definition */
/******************************/
#define EPHY_TRC_STR_FLAG(v1)  (unsigned char)(v1+0)
#define EPHY_TRC_STR_HEX(v1)  (unsigned char)(v1+2)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPHY_TRC_Init() do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_Init()
#endif
#define EPHY_TRC_Init_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x002D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPHY_TRC_WakeUp(v1) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x012D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_WakeUp(v1)
#endif
#define EPHY_TRC_WakeUp_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x012D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define EPHY_TRC_Sleep() do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_Sleep()
#endif
#define EPHY_TRC_Sleep_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_BandSupport(v1) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x032D, (short)(v1)));\
	} while(0)
#else
	#define EPHY_TRC_BandSupport(v1)
#endif
#define EPHY_TRC_BandSupport_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x032D, (short)(v1)))

#if defined(L1_CATCHER)
	#define EPHY_TRC_TEMPDAC_TABLE(v1, v2) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x042D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_TEMPDAC_TABLE(v1, v2)
#endif
#define EPHY_TRC_TEMPDAC_TABLE_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x042D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DRDI_Init(v1, v2, v3) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x052D, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_DRDI_Init(v1, v2, v3)
#endif
#define EPHY_TRC_DRDI_Init_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x052D, (short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DSDA_RX_STATUS(v1, v2) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x062D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_DSDA_RX_STATUS(v1, v2)
#endif
#define EPHY_TRC_DSDA_RX_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x062D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DSDA_TX_STATUS(v1, v2) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x072D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_DSDA_TX_STATUS(v1, v2)
#endif
#define EPHY_TRC_DSDA_TX_STATUS_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x072D, (short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_TPO_STATUS(v1, v2, v3, v4) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x082D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define EPHY_TRC_TPO_STATUS(v1, v2, v3, v4)
#endif
#define EPHY_TRC_TPO_STATUS_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x082D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define EPHY_TRC_D16_REG_DBG(v1, v2, v3, v4, v5) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x092D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)));\
	} while(0)
#else
	#define EPHY_TRC_D16_REG_DBG(v1, v2, v3, v4, v5)
#endif
#define EPHY_TRC_D16_REG_DBG_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_2_DATA(TRC_MERGE_2S(0x092D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)))

#if defined(L1_CATCHER)
	#define EPHY_TRC_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)));\
	} while(0)
#else
	#define EPHY_TRC_D32_REG_DBG(v1, v2, v3, v4, v5, v6, v7, v8, v9)
#endif
#define EPHY_TRC_D32_REG_DBG_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8, v9) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0A2D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), (unsigned char)(v3), (unsigned char)(v4), (unsigned char)(v5)), TRC_MERGE_4C((unsigned char)(v6), (unsigned char)(v7), (unsigned char)(v8), (unsigned char)(v9)))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG1(v1, v2) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B2D, (unsigned short)(v1)), (long)(v2));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG1(v1, v2)
#endif
#define EPHY_TRC_DEBUG1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0B2D, (unsigned short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG2(v1, v2, v3) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C2D, (unsigned short)(v1)), (long)(v2), (long)(v3));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG2(v1, v2, v3)
#endif
#define EPHY_TRC_DEBUG2_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x0C2D, (unsigned short)(v1)), (long)(v2), (long)(v3))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG3(v1, v2, v3, v4) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x0D2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG3(v1, v2, v3, v4)
#endif
#define EPHY_TRC_DEBUG3_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x0D2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG4(v1, v2, v3, v4, v5) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG4(v1, v2, v3, v4, v5)
#endif
#define EPHY_TRC_DEBUG4_NOFLTR(v1, v2, v3, v4, v5) TRC_SEND_5_DATA(TRC_MERGE_2S(0x0E2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG5(v1, v2, v3, v4, v5, v6) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_6_DATA(TRC_MERGE_2S(0x0F2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG5(v1, v2, v3, v4, v5, v6)
#endif
#define EPHY_TRC_DEBUG5_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_6_DATA(TRC_MERGE_2S(0x0F2D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG6(v1, v2, v3, v4, v5, v6, v7) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_7_DATA(TRC_MERGE_2S(0x102D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG6(v1, v2, v3, v4, v5, v6, v7)
#endif
#define EPHY_TRC_DEBUG6_NOFLTR(v1, v2, v3, v4, v5, v6, v7) TRC_SEND_7_DATA(TRC_MERGE_2S(0x102D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7))

#if defined(L1_CATCHER)
	#define EPHY_TRC_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(EPHY_RF_Trace_Filter[0]==1 && (EPHY_RF_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x112D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8));\
	} while(0)
#else
	#define EPHY_TRC_DEBUG7(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define EPHY_TRC_DEBUG7_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x112D, (unsigned short)(v1)), (long)(v2), (long)(v3), (long)(v4), (long)(v5), (long)(v6), (long)(v7), (long)(v8))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EPHY_RF_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_EPHY_TRC_Init(void);
void L1TRC_Send_EPHY_TRC_WakeUp(unsigned char v1);
void L1TRC_Send_EPHY_TRC_Sleep(void);
void L1TRC_Send_EPHY_TRC_BandSupport(short v1);
void L1TRC_Send_EPHY_TRC_TEMPDAC_TABLE(short v1, short v2);
void L1TRC_Send_EPHY_TRC_DRDI_Init(unsigned char v1, unsigned char v2, short v3);
void L1TRC_Send_EPHY_TRC_DSDA_RX_STATUS(unsigned char v1, short v2);
void L1TRC_Send_EPHY_TRC_DSDA_TX_STATUS(unsigned char v1, short v2);
void L1TRC_Send_EPHY_TRC_TPO_STATUS(short v1, short v2, short v3, short v4);
void L1TRC_Send_EPHY_TRC_D16_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5);
void L1TRC_Send_EPHY_TRC_D32_REG_DBG(short v1, unsigned char v2, unsigned char v3, unsigned char v4, unsigned char v5, unsigned char v6, unsigned char v7, unsigned char v8, unsigned char v9);
void L1TRC_Send_EPHY_TRC_DEBUG1(unsigned short v1, long v2);
void L1TRC_Send_EPHY_TRC_DEBUG2(unsigned short v1, long v2, long v3);
void L1TRC_Send_EPHY_TRC_DEBUG3(unsigned short v1, long v2, long v3, long v4);
void L1TRC_Send_EPHY_TRC_DEBUG4(unsigned short v1, long v2, long v3, long v4, long v5);
void L1TRC_Send_EPHY_TRC_DEBUG5(unsigned short v1, long v2, long v3, long v4, long v5, long v6);
void L1TRC_Send_EPHY_TRC_DEBUG6(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7);
void L1TRC_Send_EPHY_TRC_DEBUG7(unsigned short v1, long v2, long v3, long v4, long v5, long v6, long v7, long v8);

void Set_EPHY_RF_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EPHY_RF()	(EPHY_RF_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EPHY_RF_EPHY_RF_L()	(ChkL1ModFltr_EPHY_RF()&&((EPHY_RF_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EPHY_RF_EPHY_RF_M()	(ChkL1ModFltr_EPHY_RF()&&((EPHY_RF_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()	(ChkL1ModFltr_EPHY_RF()&&((EPHY_RF_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EPHY_RF_EPHY_DBG_L()	(ChkL1ModFltr_EPHY_RF()&&((EPHY_RF_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()	(ChkL1ModFltr_EPHY_RF()&&((EPHY_RF_Trace_Filter[1]&0x10)!=0))
#define ChkL1MsgFltr_EPHY_TRC_Init()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_L()
#define ChkL1MsgFltr_EPHY_TRC_WakeUp()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_L()
#define ChkL1MsgFltr_EPHY_TRC_Sleep()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_L()
#define ChkL1MsgFltr_EPHY_TRC_BandSupport()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_TEMPDAC_TABLE()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_DRDI_Init()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_DSDA_RX_STATUS()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_DSDA_TX_STATUS()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_TPO_STATUS()	ChkL1ClsFltr_EPHY_RF_EPHY_RF_H()
#define ChkL1MsgFltr_EPHY_TRC_D16_REG_DBG()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_D32_REG_DBG()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG1()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG2()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG3()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG4()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG5()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG6()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()
#define ChkL1MsgFltr_EPHY_TRC_DEBUG7()	ChkL1ClsFltr_EPHY_RF_EPHY_DBG_H()


#endif
