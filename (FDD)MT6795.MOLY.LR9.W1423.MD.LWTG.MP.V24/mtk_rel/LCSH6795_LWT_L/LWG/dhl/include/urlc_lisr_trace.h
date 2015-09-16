#ifndef L1TRC_URLC_DEF_H
#define L1TRC_URLC_DEF_H

/******************************/
/* String category definition */
/******************************/


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_GETBO(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_GETBO(v1)
#endif
#define URLC_TRC_GETBO_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x003E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_ZERO_BO() do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_ZERO_BO()
#endif
#define URLC_TRC_ZERO_BO_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x013E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_SELECT_SUFI(v1, v2, v3, v4) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x023E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_SELECT_SUFI(v1, v2, v3, v4)
#endif
#define URLC_TRC_SELECT_SUFI_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x023E, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_SCHEDULE_ACK(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x033E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_SCHEDULE_ACK(v1, v2)
#endif
#define URLC_TRC_SCHEDULE_ACK_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x033E, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_AM(v1, v2, v3) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x043E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_AM(v1, v2, v3)
#endif
#define URLC_TRC_TRANSMIT_AM_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x043E, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_UM(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x053E, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_UM(v1, v2)
#endif
#define URLC_TRC_TRANSMIT_UM_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x053E, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_TM(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_TM(v1)
#endif
#define URLC_TRC_TRANSMIT_TM_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x063E, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_AM_SN(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_AM_SN(v1, v2)
#endif
#define URLC_TRC_TRANSMIT_AM_SN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x073E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_RETRANSMIT_AM_SN(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083E, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define URLC_TRC_RETRANSMIT_AM_SN(v1, v2)
#endif
#define URLC_TRC_RETRANSMIT_AM_SN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x083E, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_AM_CTRL(v1, v2, v3) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_AM_CTRL(v1, v2, v3)
#endif
#define URLC_TRC_TRANSMIT_AM_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x093E, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_UM_SN(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3E, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_UM_SN(v1)
#endif
#define URLC_TRC_TRANSMIT_UM_SN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0A3E, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_TRANSMIT_DUMMY() do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_TRANSMIT_DUMMY()
#endif
#define URLC_TRC_TRANSMIT_DUMMY_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0B3E, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_NOTIFY_SETUP(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C3E, (unsigned short)(v1)));\
	} while(0)
#else
	#define URLC_TRC_NOTIFY_SETUP(v1)
#endif
#define URLC_TRC_NOTIFY_SETUP_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0C3E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_NOTIFY_RELEASE(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3E, (unsigned short)(v1)));\
	} while(0)
#else
	#define URLC_TRC_NOTIFY_RELEASE(v1)
#endif
#define URLC_TRC_NOTIFY_RELEASE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x0D3E, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_ACTIVATE_TX(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_ACTIVATE_TX(v1, v2)
#endif
#define URLC_TRC_ACTIVATE_TX_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0E3E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_ACTIVATE_TX_RES(v1, v2) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define URLC_TRC_ACTIVATE_TX_RES(v1, v2)
#endif
#define URLC_TRC_ACTIVATE_TX_RES_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x0F3E, (unsigned short)(v1)), TRC_MERGE_4C((char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define URLC_TRC_ZERO_CTRL(v1) do {\
		if(URLC_Trace_Filter[0]==1 && (URLC_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x103E, (short)(v1)));\
	} while(0)
#else
	#define URLC_TRC_ZERO_CTRL(v1)
#endif
#define URLC_TRC_ZERO_CTRL_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x103E, (short)(v1)))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char URLC_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_URLC_TRC_GETBO(char v1);
void L1TRC_Send_URLC_TRC_ZERO_BO(void);
void L1TRC_Send_URLC_TRC_SELECT_SUFI(short v1, short v2, short v3, short v4);
void L1TRC_Send_URLC_TRC_SCHEDULE_ACK(short v1, short v2);
void L1TRC_Send_URLC_TRC_TRANSMIT_AM(char v1, short v2, short v3);
void L1TRC_Send_URLC_TRC_TRANSMIT_UM(char v1, short v2);
void L1TRC_Send_URLC_TRC_TRANSMIT_TM(char v1);
void L1TRC_Send_URLC_TRC_TRANSMIT_AM_SN(unsigned char v1, unsigned char v2);
void L1TRC_Send_URLC_TRC_RETRANSMIT_AM_SN(unsigned char v1, unsigned char v2);
void L1TRC_Send_URLC_TRC_TRANSMIT_AM_CTRL(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_URLC_TRC_TRANSMIT_UM_SN(unsigned char v1);
void L1TRC_Send_URLC_TRC_TRANSMIT_DUMMY(void);
void L1TRC_Send_URLC_TRC_NOTIFY_SETUP(unsigned short v1);
void L1TRC_Send_URLC_TRC_NOTIFY_RELEASE(unsigned short v1);
void L1TRC_Send_URLC_TRC_ACTIVATE_TX(unsigned short v1, char v2);
void L1TRC_Send_URLC_TRC_ACTIVATE_TX_RES(unsigned short v1, char v2);
void L1TRC_Send_URLC_TRC_ZERO_CTRL(short v1);

void Set_URLC_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_URLC()	(URLC_Trace_Filter[0]==1)
#define ChkL1ClsFltr_URLC_URLC_GETBO_M()	(ChkL1ModFltr_URLC()&&((URLC_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()	(ChkL1ModFltr_URLC()&&((URLC_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_URLC_URLC_CONFIG_M()	(ChkL1ModFltr_URLC()&&((URLC_Trace_Filter[1]&0x04)!=0))
#define ChkL1MsgFltr_URLC_TRC_GETBO()	ChkL1ClsFltr_URLC_URLC_GETBO_M()
#define ChkL1MsgFltr_URLC_TRC_ZERO_BO()	ChkL1ClsFltr_URLC_URLC_GETBO_M()
#define ChkL1MsgFltr_URLC_TRC_SELECT_SUFI()	ChkL1ClsFltr_URLC_URLC_GETBO_M()
#define ChkL1MsgFltr_URLC_TRC_SCHEDULE_ACK()	ChkL1ClsFltr_URLC_URLC_GETBO_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_AM()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_UM()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_TM()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_AM_SN()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_RETRANSMIT_AM_SN()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_AM_CTRL()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_UM_SN()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_TRANSMIT_DUMMY()	ChkL1ClsFltr_URLC_URLC_TRANSMIT_M()
#define ChkL1MsgFltr_URLC_TRC_NOTIFY_SETUP()	ChkL1ClsFltr_URLC_URLC_CONFIG_M()
#define ChkL1MsgFltr_URLC_TRC_NOTIFY_RELEASE()	ChkL1ClsFltr_URLC_URLC_CONFIG_M()
#define ChkL1MsgFltr_URLC_TRC_ACTIVATE_TX()	ChkL1ClsFltr_URLC_URLC_CONFIG_M()
#define ChkL1MsgFltr_URLC_TRC_ACTIVATE_TX_RES()	ChkL1ClsFltr_URLC_URLC_CONFIG_M()
#define ChkL1MsgFltr_URLC_TRC_ZERO_CTRL()	ChkL1ClsFltr_URLC_URLC_GETBO_M()


#endif
