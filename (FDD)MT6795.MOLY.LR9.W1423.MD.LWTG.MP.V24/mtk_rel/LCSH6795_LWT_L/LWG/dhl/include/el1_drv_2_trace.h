#ifndef L1TRC_EL1_DRV_2_DEF_H
#define L1TRC_EL1_DRV_2_DEF_H

/******************************/
/* String category definition */
/******************************/
#define DRV_Dynm_Id_String(v1)  (unsigned char)(v1+0)
#define DRV_Send_Msg_String(v1)  (unsigned char)(v1+14)


/****************************/
/* Message macro definition */
/****************************/
#include "L1Trc.h"
#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DYNM_CMD_HDR(v1, v2, v3) do {\
		if(EL1_DRV_2_Trace_Filter[0]==1 && (EL1_DRV_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0005, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_DYNM_CMD_HDR(v1, v2, v3)
#endif
#define DRV_LOG_DYNM_CMD_HDR_NOFLTR(v1, v2, v3) TRC_SEND_2_DATA(TRC_MERGE_1S2C(0x0005, (unsigned char)(v1), (unsigned char)(v2)), TRC_MERGE_4C((unsigned char)(v3), TRC_BOXSTER_PAD, TRC_BOXSTER_PAD, TRC_BOXSTER_PAD))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_DYNM_RPT_HDR(v1, v2) do {\
		if(EL1_DRV_2_Trace_Filter[0]==1 && (EL1_DRV_2_Trace_Filter[1]&0x10)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0105, (unsigned char)(v1), (unsigned char)(v2)));\
	} while(0)
#else
	#define DRV_LOG_DYNM_RPT_HDR(v1, v2)
#endif
#define DRV_LOG_DYNM_RPT_HDR_NOFLTR(v1, v2) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0105, (unsigned char)(v1), (unsigned char)(v2)))

#if defined(L1_CATCHER) && ( !defined(_L1_DISABLE_TRACE_LEVEL_) || (_L1_DISABLE_TRACE_LEVEL_ < 1) )
	#define DRV_LOG_MSG_SND(v1) do {\
		if(EL1_DRV_2_Trace_Filter[0]==1 && (EL1_DRV_2_Trace_Filter[1]&0x02)!=0 )\
			TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0205, (unsigned char)(v1), TRC_BOXSTER_PAD));\
	} while(0)
#else
	#define DRV_LOG_MSG_SND(v1)
#endif
#define DRV_LOG_MSG_SND_NOFLTR(v1) TRC_SEND_1_DATA(TRC_MERGE_1S2C(0x0205, (unsigned char)(v1), TRC_BOXSTER_PAD))



/*******************************/
/* declaration of filter array */
/*******************************/
extern unsigned char EL1_DRV_2_Trace_Filter[5];
/*************************/
/* Function declarations */
/*************************/
#ifdef L1_CATCHER

void L1TRC_Send_DRV_LOG_DYNM_CMD_HDR(unsigned char v1, unsigned char v2, unsigned char v3);
void L1TRC_Send_DRV_LOG_DYNM_RPT_HDR(unsigned char v1, unsigned char v2);
void L1TRC_Send_DRV_LOG_MSG_SND(unsigned char v1);

void Set_EL1_DRV_2_Filter(unsigned char *setting);

#endif

/************************************/
/* Filter checking API declarations */
/************************************/

#define ChkL1ModFltr_EL1_DRV_2()	(EL1_DRV_2_Trace_Filter[0]==1)
#define ChkL1ClsFltr_EL1_DRV_2_drv_func_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x01)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_func_trace_1()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x02)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_func_trace_2()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x04)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_math_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x08)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_var_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x10)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_var_trace_l()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x20)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_var_trace_2()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x40)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_flow_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[1]&0x80)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_flow_trace_1()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[2]&0x01)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_flow_trace_2()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[2]&0x02)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_error_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[2]&0x04)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_param_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[2]&0x08)!=0))
#define ChkL1ClsFltr_EL1_DRV_2_drv_fws_trace()	(ChkL1ModFltr_EL1_DRV_2()&&((EL1_DRV_2_Trace_Filter[2]&0x10)!=0))
#define ChkL1MsgFltr_DRV_LOG_DYNM_CMD_HDR()	ChkL1ClsFltr_EL1_DRV_2_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_DYNM_RPT_HDR()	ChkL1ClsFltr_EL1_DRV_2_drv_var_trace()
#define ChkL1MsgFltr_DRV_LOG_MSG_SND()	ChkL1ClsFltr_EL1_DRV_2_drv_func_trace_1()


#endif
