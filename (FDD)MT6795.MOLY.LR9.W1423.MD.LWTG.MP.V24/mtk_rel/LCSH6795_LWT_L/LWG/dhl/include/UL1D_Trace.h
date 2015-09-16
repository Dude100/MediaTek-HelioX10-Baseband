#ifndef L1TRC_UL1D_PRI_DEF_H
#define L1TRC_UL1D_PRI_DEF_H

/******************************/
/* String category definition */
/******************************/
#define UL1D_TRC_STR_DBG_EVENT(v1)  (unsigned char)(v1+0)
#define UL1D_TRC_STR_TIME_MARGIN(v1)  (unsigned char)(v1+40)
#define UL1D_TRC_STR_CH(v1)  (unsigned char)(v1+64)
#define UL1D_TRC_STR_EVENT(v1)  (unsigned char)(v1+75)
#define UL1D_TRC_STR_UL1D_MLT_DATA_ID_T(v1)  (unsigned char)(v1+79)
#define UL1D_TRC_STR_AGC_MODE(v1)  (unsigned char)(v1+85)
#define UL1D_TRC_STR_LNA_STATE(v1)  (unsigned char)(v1+88)
#define UL1_Multi_Afc_rat(v1)  (unsigned char)(v1+91)
#define UL1D_TRC_STR_DUAL_AFC_MODE(v1)  (unsigned char)(v1+96)
#define UL1D_TRC_STR_AFC_STATUS(v1)  (unsigned char)(v1+99)
#define UL1D_TRC_STR_DUAL_AFC_UL1C_ASK_MSG(v1)  (unsigned char)(v1+120)
#define UL1D_TRC_STR_STATE(v1)  (unsigned char)(v1+139)
#define UL1D_TRC_STR_MODE(v1)  (unsigned char)(v1+151)
#define UL1D_TRC_STR_UL1D_STATE(v1)  (unsigned char)(v1+161)
#define UL1D_TRC_STR_ERROR_MESSAGE(v1)  (unsigned char)(v1+174)
#define UL1D_TRC_STR_RX_ADC_MODE(v1)  (unsigned char)(v1+179)
#define UL1D_TRC_STR_RX_PATH(v1)  (unsigned char)(v1+181)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_EVENT_SLOT_ECHIPS(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x002D, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EVENT_SLOT_ECHIPS(v1, v2, v3)
#endif
#define UL1D_TRC_EVENT_SLOT_ECHIPS_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x002D, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_TIME_MARGIN(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x012D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_TIME_MARGIN(v1, v2)
#endif
#define UL1D_TRC_TIME_MARGIN_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x012D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_LOG3G_SCALER_START(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_LOG3G_SCALER_START(v1)
#endif
#define UL1D_TRC_LOG3G_SCALER_START_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x022D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_LOG3G_TRIGGER(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x032D, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_LOG3G_TRIGGER(v1, v2, v3)
#endif
#define UL1D_TRC_LOG3G_TRIGGER_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x032D, (unsigned short)(v2)), TRC_MERGE_4C((unsigned char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_LOG3G_UL1D_LOG_STS(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x042D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_LOG3G_UL1D_LOG_STS(v1)
#endif
#define UL1D_TRC_LOG3G_UL1D_LOG_STS_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x042D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_LOG3G_USB_BUF_STS3(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x052D, (unsigned short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_LOG3G_USB_BUF_STS3(v1)
#endif
#define UL1D_TRC_LOG3G_USB_BUF_STS3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x052D, (unsigned short)(v1)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CHECK_SLEEP(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x062D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CHECK_SLEEP(v1, v2)
#endif
#define UL1D_TRC_CHECK_SLEEP_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x062D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CHECK_SLEEP2(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x072D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_CHECK_SLEEP2(v1, v2, v3)
#endif
#define UL1D_TRC_CHECK_SLEEP2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x072D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CHECK_SLEEP3(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x082D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CHECK_SLEEP3(v1, v2)
#endif
#define UL1D_TRC_CHECK_SLEEP3_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x082D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_WAKEUP_HISR(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x092D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_WAKEUP_HISR(v1, v2)
#endif
#define UL1D_TRC_WAKEUP_HISR_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x092D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0A2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0A2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN2(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN2(v1, v2)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN2_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x0B2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN3(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN3(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN3_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0C2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN4(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN4(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN4_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN5(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0E2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN5(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN5_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x0E2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_MIN_TIME_MARGIN6(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_MARGIN6(v1, v2, v3)
#endif
#define UL1D_TRC_MIN_TIME_MARGIN6_NOFLTR(v1, v2, v3) TRC_SEND_4_DATA(TRC_MERGE_1S2C(0x0F2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MIN_TIME_DGB(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x102D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_DGB(v1, v2, v3, v4)
#endif
#define UL1D_TRC_MIN_TIME_DGB_NOFLTR(v1, v2, v3, v4) TRC_SEND_5_DATA(TRC_MERGE_1S2C(0x102D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_MIN_TIME_DGB1(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x112D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_MIN_TIME_DGB1(v1, v2)
#endif
#define UL1D_TRC_MIN_TIME_DGB1_NOFLTR(v1, v2) TRC_SEND_3_DATA(TRC_MERGE_1S2C(0x112D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1), (unsigned long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_STATE_CHANGE(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x122D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_STATE_CHANGE(v1, v2)
#endif
#define UL1D_TRC_STATE_CHANGE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x122D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RTR_TIME_EXTEND(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x132D, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RTR_TIME_EXTEND(v1, v2, v3)
#endif
#define UL1D_TRC_RTR_TIME_EXTEND_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x132D, (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v1), (unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_RF_ERR(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x142D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_RF_ERR(v1, v2, v3, v4)
#endif
#define UL1D_TRC_DUAL_RF_ERR_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x142D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MM_RF_ERR(v1, v2, v3, v4, v5, v6, v7, v8) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_8_DATA(TRC_MERGE_2S(0x152D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8));\
	} while(0)
#else
	#define UL1D_TRC_MM_RF_ERR(v1, v2, v3, v4, v5, v6, v7, v8)
#endif
#define UL1D_TRC_MM_RF_ERR_NOFLTR(v1, v2, v3, v4, v5, v6, v7, v8) TRC_SEND_8_DATA(TRC_MERGE_2S(0x152D, (short)(v1)), (unsigned long)(v2), (unsigned long)(v3), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6), (unsigned long)(v7), (unsigned long)(v8))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MIPI_TRX(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x162D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_MIPI_TRX(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_MIPI_TRX_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x162D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), (unsigned long)(v4), (unsigned long)(v5), (unsigned long)(v6))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RF_DUMP_ERR(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x172D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RF_DUMP_ERR(v1, v2, v3)
#endif
#define UL1D_TRC_RF_DUMP_ERR_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x172D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_RX_PATH_SELECT(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182D, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_RX_PATH_SELECT(v1, v2, v3)
#endif
#define UL1D_TRC_RX_PATH_SELECT_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x182D, (unsigned char)(v1), (unsigned char)(v2)), (unsigned long)(v3))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EVENT_CH_ON(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x192D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EVENT_CH_ON(v1, v2, v3)
#endif
#define UL1D_TRC_EVENT_CH_ON_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x192D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EVENT_CH_OFF(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A2D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EVENT_CH_OFF(v1)
#endif
#define UL1D_TRC_EVENT_CH_OFF_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1A2D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_EVENT_MISC(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B2D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_EVENT_MISC(v1)
#endif
#define UL1D_TRC_EVENT_MISC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1B2D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TIMING_ADJ_IDLE(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C2D, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_TIMING_ADJ_IDLE(v1)
#endif
#define UL1D_TRC_TIMING_ADJ_IDLE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x1C2D, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_TIMING_ADJ_IDLE2(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D2D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)));\
	} while(0)
#else
	#define UL1D_TRC_TIMING_ADJ_IDLE2(v1, v2, v3)
#endif
#define UL1D_TRC_TIMING_ADJ_IDLE2_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x1D2D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (short)(v3)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_MISC_SIM_TYPE(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2D, (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_MISC_SIM_TYPE(v1)
#endif
#define UL1D_TRC_MISC_SIM_TYPE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x1E2D, (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_PAC_EVENT(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_PAC_EVENT(v1, v2)
#endif
#define UL1D_TRC_PAC_EVENT_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x1F2D, (unsigned char)(v1), TRC_BOXSTER_PAD), (unsigned long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_INVALID_TIMER_START(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x202D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), (unsigned char)(v5)), (unsigned long)(v2), (unsigned long)(v6));\
	} while(0)
#else
	#define UL1D_TRC_INVALID_TIMER_START(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_INVALID_TIMER_START_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_4_DATA(TRC_MERGE_2S(0x202D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), (unsigned char)(v3), (unsigned char)(v5)), (unsigned long)(v2), (unsigned long)(v6))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CELL_STATE_PARAM(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x212D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_CELL_STATE_PARAM(v1, v2, v3)
#endif
#define UL1D_TRC_CELL_STATE_PARAM_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x212D, (unsigned short)(v1)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v2))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_CELL_STATE_PARAM2(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x01)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x222D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_CELL_STATE_PARAM2(v1, v2)
#endif
#define UL1D_TRC_CELL_STATE_PARAM2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x222D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RECOVERTIME_INFO(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x232D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_RECOVERTIME_INFO(v1, v2)
#endif
#define UL1D_TRC_RECOVERTIME_INFO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x232D, (unsigned short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_FASTSLEEP_INFO(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x242D, (short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_FASTSLEEP_INFO(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FASTSLEEP_INFO_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x242D, (short)(v2)), TRC_MERGE_2S((unsigned short)(v3), (unsigned short)(v4)), (unsigned long)(v1))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FDD_PHY_CAPABILITY(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x252D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_FDD_PHY_CAPABILITY(v1, v2)
#endif
#define UL1D_TRC_FDD_PHY_CAPABILITY_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x252D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FDD_PHY_CAPABILITY2(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x262D, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FDD_PHY_CAPABILITY2(v1, v2, v3, v4)
#endif
#define UL1D_TRC_FDD_PHY_CAPABILITY2_NOFLTR(v1, v2, v3, v4) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x262D, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), (unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_FDD_PHY_CAPABILITY3(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x272D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_FDD_PHY_CAPABILITY3(v1)
#endif
#define UL1D_TRC_FDD_PHY_CAPABILITY3_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x272D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_GAP_PATTERN(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x282D, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_GAP_PATTERN(v1)
#endif
#define UL1D_TRC_GAP_PATTERN_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x282D, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_GAP_STOP() do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x292D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_GAP_STOP()
#endif
#define UL1D_TRC_GAP_STOP_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x292D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TM_SYNC_TM_OFF(v1, v2, v3, v4, v5, v6) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_5_DATA(TRC_MERGE_2S(0x2A2D, (unsigned short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v6)), (long)(v1), (long)(v3), (long)(v5));\
	} while(0)
#else
	#define UL1D_TRC_TM_SYNC_TM_OFF(v1, v2, v3, v4, v5, v6)
#endif
#define UL1D_TRC_TM_SYNC_TM_OFF_NOFLTR(v1, v2, v3, v4, v5, v6) TRC_SEND_5_DATA(TRC_MERGE_2S(0x2A2D, (unsigned short)(v2)), TRC_MERGE_2S((short)(v4), (short)(v6)), (long)(v1), (long)(v3), (long)(v5))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_RTR_SYNC_FRMCNT(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_RTR_SYNC_FRMCNT(v1)
#endif
#define UL1D_TRC_RTR_SYNC_FRMCNT_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2B2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_TM_SYNC_TM_OFF_US(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_TM_SYNC_TM_OFF_US(v1)
#endif
#define UL1D_TRC_TM_SYNC_TM_OFF_US_NOFLTR(v1) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x2C2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_DM_ERROR_MESSAGE() do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x08)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DM_ERROR_MESSAGE()
#endif
#define UL1D_TRC_DM_ERROR_MESSAGE_NOFLTR() TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x2D2D, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_DAC_3G_TO_2G(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E2D, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_DAC_3G_TO_2G(v1)
#endif
#define UL1D_TRC_DUAL_AFC_DAC_3G_TO_2G_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2E2D, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_DAC_2G_TO_3G(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x2F2D, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_DAC_2G_TO_3G(v1)
#endif
#define UL1D_TRC_DUAL_AFC_DAC_2G_TO_3G_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x2F2D, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_STATE(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x302D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_STATE(v1, v2)
#endif
#define UL1D_TRC_DUAL_AFC_STATE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x302D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_MODE(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x312D, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_MODE(v1, v2)
#endif
#define UL1D_TRC_DUAL_AFC_MODE_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x312D, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_Set_SWMODE_DAC(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_2S(0x322D, (short)(v1)));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_Set_SWMODE_DAC(v1)
#endif
#define UL1D_TRC_DUAL_AFC_Set_SWMODE_DAC_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_2S(0x322D, (short)(v1)))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_Set_DFTC_DAC(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x332D, (short)(v1)), (long)(v2));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_Set_DFTC_DAC(v1, v2)
#endif
#define UL1D_TRC_DUAL_AFC_Set_DFTC_DAC_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x332D, (short)(v1)), (long)(v2))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_DAC_SHARING(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x342D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_DAC_SHARING(v1, v2)
#endif
#define UL1D_TRC_DUAL_AFC_DAC_SHARING_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x342D, (short)(v1)), TRC_MERGE_4C((unsigned char)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_DUAL_AFC_UL1C_ASK(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x40)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x352D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_DUAL_AFC_UL1C_ASK(v1)
#endif
#define UL1D_TRC_DUAL_AFC_UL1C_ASK_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x352D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_AFC_DUAL_MODE(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x362D, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_AFC_DUAL_MODE(v1, v2, v3)
#endif
#define UL1D_TRC_HW_AFC_DUAL_MODE_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x362D, (unsigned short)(v1)), TRC_MERGE_1S2C((short)(v3), (char)(v2), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_AFC_DAC_MODE(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x372D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_AFC_DAC_MODE(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_AFC_DAC_MODE_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x372D, (unsigned short)(v1)), TRC_MERGE_2S((unsigned short)(v2), (unsigned short)(v3)), TRC_MERGE_4C((unsigned char)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 2) )
	#define UL1D_TRC_META_AFC_CTRL(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[2]&0x01)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x382D, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1));\
	} while(0)
#else
	#define UL1D_TRC_META_AFC_CTRL(v1, v2, v3)
#endif
#define UL1D_TRC_META_AFC_CTRL_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x382D, (unsigned short)(v2)), TRC_MERGE_1S2C((unsigned short)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v1))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_AFC_POWEROFF(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x392D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_AFC_POWEROFF(v1, v2)
#endif
#define UL1D_TRC_AFC_POWEROFF_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x392D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_AFC_STA(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A2D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_AFC_STA(v1, v2, v3)
#endif
#define UL1D_TRC_HW_AFC_STA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3A2D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_HW_FOE_MNTR1(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[2]&0x02)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_FOE_MNTR1(v1, v2)
#endif
#define UL1D_TRC_HW_FOE_MNTR1_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3B2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_FOE_MNTR2(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_FOE_MNTR2(v1, v2)
#endif
#define UL1D_TRC_HW_FOE_MNTR2_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3C2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_AGC_MODE(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D2D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_AGC_MODE(v1)
#endif
#define UL1D_TRC_HW_AGC_MODE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x3D2D, (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_AGC_TRACKING(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E2D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_AGC_TRACKING(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_AGC_TRACKING_NOFLTR(v1, v2, v3, v4) TRC_SEND_3_DATA(TRC_MERGE_2S(0x3E2D, (short)(v1)), TRC_MERGE_2S((short)(v2), (short)(v3)), TRC_MERGE_1S2C((short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_DCO(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_DCO(v1, v2)
#endif
#define UL1D_TRC_HW_RXBFE_DCO_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x3F2D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_DCOH(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x402D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_DCOH(v1, v2)
#endif
#define UL1D_TRC_HW_RXBFE_DCOH_NOFLTR(v1, v2) TRC_SEND_2_DATA(TRC_MERGE_2S(0x402D, (short)(v1)), TRC_MERGE_1S2C((short)(v2), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_GAIN(v1, v2) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x412D, (char)(v1), (char)(v2)));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_GAIN(v1, v2)
#endif
#define UL1D_TRC_HW_RXBFE_GAIN_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x412D, (char)(v1), (char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_RSSI(v1, v2, v3, v4) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_4_DATA(TRC_MERGE_2S(0x422D, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_RSSI(v1, v2, v3, v4)
#endif
#define UL1D_TRC_HW_RXBFE_RSSI_NOFLTR(v1, v2, v3, v4) TRC_SEND_4_DATA(TRC_MERGE_2S(0x422D, (short)(v1)), TRC_MERGE_1S2C((unsigned short)(v4), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (unsigned long)(v2), (unsigned long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_AGCSET(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_3_DATA(TRC_MERGE_2S(0x432D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_AGCSET(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXBFE_AGCSET_NOFLTR(v1, v2, v3) TRC_SEND_3_DATA(TRC_MERGE_2S(0x432D, (short)(v2)), TRC_MERGE_4C((char)(v1), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD), (long)(v3))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define UL1D_TRC_HW_RXBFE_RFSTA(v1, v2, v3) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[1]&0x80)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_2S(0x442D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_HW_RXBFE_RFSTA(v1, v2, v3)
#endif
#define UL1D_TRC_HW_RXBFE_RFSTA_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_2S(0x442D, (short)(v2)), TRC_MERGE_1S2C((short)(v3), (unsigned char)(v1), TRC_BOXSTER_PAD))

#if defined(L1_CATCHER)
	#define UL1D_TRC_ERROR_MESSAGE(v1) do {\
		if(UL1D_PRI_Trace_Filter[0]==1 && (UL1D_PRI_Trace_Filter[2]&0x04)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x452D, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define UL1D_TRC_ERROR_MESSAGE(v1)
#endif
#define UL1D_TRC_ERROR_MESSAGE_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x452D, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char UL1D_PRI_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_UL1D_TRC_EVENT_SLOT_ECHIPS(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_TIME_MARGIN(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_LOG3G_SCALER_START(unsigned char v1);
void L1TRC_Send_UL1D_TRC_LOG3G_TRIGGER(unsigned char v1, unsigned short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_LOG3G_UL1D_LOG_STS(unsigned long v1);
void L1TRC_Send_UL1D_TRC_LOG3G_USB_BUF_STS3(unsigned short v1);
void L1TRC_Send_UL1D_TRC_CHECK_SLEEP(unsigned short v1, unsigned short v2);
void L1TRC_Send_UL1D_TRC_CHECK_SLEEP2(unsigned short v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_CHECK_SLEEP3(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_WAKEUP_HISR(short v1, short v2);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN2(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN3(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN4(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN5(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MIN_TIME_MARGIN6(unsigned long v1, unsigned long v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_MIN_TIME_DGB(unsigned long v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MIN_TIME_DGB1(unsigned long v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_STATE_CHANGE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_RTR_TIME_EXTEND(unsigned char v1, unsigned char v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_DUAL_RF_ERR(short v1, unsigned long v2, unsigned long v3, unsigned long v4);
void L1TRC_Send_UL1D_TRC_MM_RF_ERR(short v1, unsigned long v2, unsigned long v3, unsigned long v4, unsigned long v5, unsigned long v6, unsigned long v7, unsigned long v8);
void L1TRC_Send_UL1D_TRC_MIPI_TRX(short v1, short v2, short v3, unsigned long v4, unsigned long v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_RF_DUMP_ERR(short v1, short v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_RX_PATH_SELECT(unsigned char v1, unsigned char v2, unsigned long v3);
void L1TRC_Send_UL1D_TRC_EVENT_CH_ON(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_EVENT_CH_OFF(unsigned char v1);
void L1TRC_Send_UL1D_TRC_EVENT_MISC(unsigned char v1);
void L1TRC_Send_UL1D_TRC_TIMING_ADJ_IDLE(short v1);
void L1TRC_Send_UL1D_TRC_TIMING_ADJ_IDLE2(unsigned short v1, unsigned short v2, short v3);
void L1TRC_Send_UL1D_TRC_MISC_SIM_TYPE(char v1);
void L1TRC_Send_UL1D_TRC_PAC_EVENT(unsigned char v1, unsigned long v2);
void L1TRC_Send_UL1D_TRC_INVALID_TIMER_START(unsigned short v1, unsigned long v2, unsigned char v3, unsigned short v4, unsigned char v5, unsigned long v6);
void L1TRC_Send_UL1D_TRC_CELL_STATE_PARAM(unsigned short v1, long v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_CELL_STATE_PARAM2(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_RECOVERTIME_INFO(unsigned short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_FASTSLEEP_INFO(unsigned long v1, short v2, unsigned short v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_FDD_PHY_CAPABILITY(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_FDD_PHY_CAPABILITY2(unsigned char v1, unsigned char v2, unsigned char v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_FDD_PHY_CAPABILITY3(unsigned char v1);
void L1TRC_Send_UL1D_TRC_GAP_PATTERN(short v1);
void L1TRC_Send_UL1D_TRC_GAP_STOP(void);
void L1TRC_Send_UL1D_TRC_TM_SYNC_TM_OFF(long v1, unsigned short v2, long v3, short v4, long v5, short v6);
void L1TRC_Send_UL1D_TRC_RTR_SYNC_FRMCNT(unsigned long v1);
void L1TRC_Send_UL1D_TRC_TM_SYNC_TM_OFF_US(long v1);
void L1TRC_Send_UL1D_TRC_DM_ERROR_MESSAGE(void);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_DAC_3G_TO_2G(short v1);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_DAC_2G_TO_3G(short v1);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_STATE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_MODE(unsigned char v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_Set_SWMODE_DAC(short v1);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_Set_DFTC_DAC(short v1, long v2);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_DAC_SHARING(short v1, unsigned char v2);
void L1TRC_Send_UL1D_TRC_DUAL_AFC_UL1C_ASK(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HW_AFC_DUAL_MODE(unsigned short v1, char v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_AFC_DAC_MODE(unsigned short v1, unsigned short v2, unsigned short v3, unsigned char v4);
void L1TRC_Send_UL1D_TRC_META_AFC_CTRL(long v1, unsigned short v2, unsigned short v3);
void L1TRC_Send_UL1D_TRC_AFC_POWEROFF(char v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_AFC_STA(char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_HW_FOE_MNTR1(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_FOE_MNTR2(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_AGC_MODE(unsigned char v1);
void L1TRC_Send_UL1D_TRC_HW_AGC_TRACKING(short v1, short v2, short v3, short v4);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_DCO(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_DCOH(short v1, short v2);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_GAIN(char v1, char v2);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_RSSI(short v1, unsigned long v2, unsigned long v3, unsigned short v4);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_AGCSET(char v1, short v2, long v3);
void L1TRC_Send_UL1D_TRC_HW_RXBFE_RFSTA(unsigned char v1, short v2, short v3);
void L1TRC_Send_UL1D_TRC_ERROR_MESSAGE(unsigned char v1);

void Set_UL1D_PRI_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_UL1D_PRI()	(UL1D_PRI_Trace_Filter[0]==1)
#define ChkL1ClsFltr_UL1D_PRI_COMMON_L()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PRI_COMMON_M()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PRI_COMMON_H()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_UL1D_PRI_DM_M()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_UL1D_PRI_DM_H()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_UL1D_PRI_DualAFC_M()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_UL1D_PRI_DualAFC_H()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_UL1D_PRI_MODEM_L()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_UL1D_PRI_MODEM_M()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_UL1D_PRI_MODEM_H()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_UL1D_PRI_ERROR_H()	(ChkL1ModFltr_UL1D_PRI()&&((UL1D_PRI_Trace_Filter[2]&0x04)!=0))
#define ChkL1MsgFltr_UL1D_TRC_EVENT_SLOT_ECHIPS()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_TIME_MARGIN()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_LOG3G_SCALER_START()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_LOG3G_TRIGGER()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_LOG3G_UL1D_LOG_STS()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_LOG3G_USB_BUF_STS3()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_CHECK_SLEEP()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_CHECK_SLEEP2()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_CHECK_SLEEP3()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_WAKEUP_HISR()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN2()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN3()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN4()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN5()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_MARGIN6()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_DGB()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_MIN_TIME_DGB1()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_STATE_CHANGE()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_RTR_TIME_EXTEND()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_RF_ERR()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_MM_RF_ERR()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_MIPI_TRX()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_RF_DUMP_ERR()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_RX_PATH_SELECT()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_EVENT_CH_ON()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_EVENT_CH_OFF()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_EVENT_MISC()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_TIMING_ADJ_IDLE()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_TIMING_ADJ_IDLE2()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_MISC_SIM_TYPE()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_PAC_EVENT()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_INVALID_TIMER_START()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_CELL_STATE_PARAM()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_CELL_STATE_PARAM2()	ChkL1ClsFltr_UL1D_PRI_COMMON_L()
#define ChkL1MsgFltr_UL1D_TRC_RECOVERTIME_INFO()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_FASTSLEEP_INFO()	ChkL1ClsFltr_UL1D_PRI_COMMON_M()
#define ChkL1MsgFltr_UL1D_TRC_FDD_PHY_CAPABILITY()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_FDD_PHY_CAPABILITY2()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_FDD_PHY_CAPABILITY3()	ChkL1ClsFltr_UL1D_PRI_COMMON_H()
#define ChkL1MsgFltr_UL1D_TRC_GAP_PATTERN()	ChkL1ClsFltr_UL1D_PRI_DM_H()
#define ChkL1MsgFltr_UL1D_TRC_GAP_STOP()	ChkL1ClsFltr_UL1D_PRI_DM_H()
#define ChkL1MsgFltr_UL1D_TRC_TM_SYNC_TM_OFF()	ChkL1ClsFltr_UL1D_PRI_DM_M()
#define ChkL1MsgFltr_UL1D_TRC_RTR_SYNC_FRMCNT()	ChkL1ClsFltr_UL1D_PRI_DM_M()
#define ChkL1MsgFltr_UL1D_TRC_TM_SYNC_TM_OFF_US()	ChkL1ClsFltr_UL1D_PRI_DM_M()
#define ChkL1MsgFltr_UL1D_TRC_DM_ERROR_MESSAGE()	ChkL1ClsFltr_UL1D_PRI_DM_M()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_DAC_3G_TO_2G()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_DAC_2G_TO_3G()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_STATE()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_MODE()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_Set_SWMODE_DAC()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_Set_DFTC_DAC()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_DAC_SHARING()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_DUAL_AFC_UL1C_ASK()	ChkL1ClsFltr_UL1D_PRI_DualAFC_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_AFC_DUAL_MODE()	ChkL1ClsFltr_UL1D_PRI_MODEM_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_AFC_DAC_MODE()	ChkL1ClsFltr_UL1D_PRI_MODEM_H()
#define ChkL1MsgFltr_UL1D_TRC_META_AFC_CTRL()	ChkL1ClsFltr_UL1D_PRI_MODEM_M()
#define ChkL1MsgFltr_UL1D_TRC_AFC_POWEROFF()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_AFC_STA()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_FOE_MNTR1()	ChkL1ClsFltr_UL1D_PRI_MODEM_H()
#define ChkL1MsgFltr_UL1D_TRC_HW_FOE_MNTR2()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_AGC_MODE()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_AGC_TRACKING()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_DCO()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_DCOH()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_GAIN()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_RSSI()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_AGCSET()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_HW_RXBFE_RFSTA()	ChkL1ClsFltr_UL1D_PRI_MODEM_L()
#define ChkL1MsgFltr_UL1D_TRC_ERROR_MESSAGE()	ChkL1ClsFltr_UL1D_PRI_ERROR_H()


#endif
