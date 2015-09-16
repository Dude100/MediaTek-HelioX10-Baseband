#ifndef __SIM_DRV_SW_API_H__
#define __SIM_DRV_SW_API_H__
#include "multi_icc_custom.h"

#ifdef DRV_SIM_BUILD_SINGLE_SIM
//extern kal_uint16 SIM_CMD(kal_uint8  *txData,kal_uint16  txSize,kal_uint8  *result,kal_uint16  *rcvSize, kal_uint8 *Error);
extern void L1sim_ChangeBaud(void);
extern void L1sim_NormalBaud(void);
extern sim_card_speed_type L1sim_Get_CardSpeedType(void);
extern void L1sim_Enable_Enhanced_Speed(kal_bool enable);
extern kal_uint16 L1sim_Cmd_Layer(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize);

extern void SIM1_LDO_enable(kal_bool enable);
extern void SIM2_LDO_enable(kal_bool enable);

usim_status_enum L1sim_Reset_All(sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm);
void L1sim_Enable_Enhanced_Speed_All(kal_bool enable);
kal_bool L1sim_Set_ClockStopMode_All(sim_clock_stop_enum mode);
void L1sim_PowerOff_All(void);
void L1sim_Get_Card_Info_All(sim_info_struct *info);
sim_status L1sim_Cmd_All(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize);
void L1sim_Select_SIM_PLUS(kal_bool isSIMPLUS);
void L1sim_Select_Prefer_PhyLayer_All(sim_protocol_phy_enum T);
#endif

sim_HW_cb *sim_get_hwCb(kal_uint32 simInterface);
kal_uint32 sim_get_logical_from_SIMIF(kal_uint32 HWIf);
void SIM_StartFaltalReport(sim_HW_cb *hw_cb);
kal_uint8 DRV_ICC_GPTI_GetHandle(kal_uint32 *handle);
void DRV_ICC_GPTI_StopItem(kal_uint32 handle);
kal_bool DRV_ICC_GPTI_StartItem(kal_uint32 handle,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
kal_uint8 DRV_ICC_makeCLA(kal_uint8 CLAHighBits, kal_uint8 CLAFromApdu);
extern void sim_MT6302_init(void);
extern sim_status L1sim_Cmd_Layer_MT6302(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb, kal_bool *isSW6263);
extern void sim_addMsg(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2);
extern void sim_set_logical_to_SIMIF(kal_uint32 HWIf, kal_uint32 logical);
/* custom setting */
extern kal_uint32 sim_get_logicalNum_from_app(SIM_ICC_APPLICATION application);
extern kal_uint32 sim_get_MT6302_from_logicalNum(kal_uint32 logicalNum);
extern kal_uint32 sim_get_hwCtrl_from_logicalNum(kal_uint32 logicalNum);
extern kal_uint32 sim_get_MT6302PeerInterface(kal_uint8 chipNum, kal_uint32 portNum);
extern kal_uint32 sim_custom_task_2_driver(kal_uint32 taskInterface);
extern void *kal_get_current_thread_ID(void);
extern void L1sim_Set_Slt_Rlt(kal_bool rlt, SIM_ICC_APPLICATION application);

#ifndef __TBD__
extern kal_uint32 SIM_GetCurrentTime(void);
extern kal_uint32 SIM_GetDurationTick(kal_uint32 previous_time, kal_uint32 current_time);
#endif

#ifndef __FPGA__
void DRV_ICC_PMU_setVolt(kal_uint32 hwInterfaceNo, usim_power_enum volt);
void DRV_ICC_PMU_switch(kal_uint32 hwInterfaceNo, kal_bool enable);
#if defined(__DRV_SIM_LP_MODE__)
void DRV_ICC_SetLp(kal_uint32 hwInterfaceNo, kal_bool isOn);
#endif
#endif

extern void SIM_SetRXTIDE(kal_uint16 RXTIDE, sim_HW_cb *hw_cb);
extern void SIM_SetTXTIDE(kal_uint16 _TXTIDE, sim_HW_cb *hw_cb);
extern void L1sim_Enable_Enhanced_Speed(kal_bool enable, sim_HW_cb *hw_cb);
extern void USIM_SET_EVENT_Multiple(usim_dcb_struct *usim_dcb);
extern void SIM_SetTOUT(kal_uint32 TOUT, sim_HW_cb *hw_cb);
extern void DRV_ICC_print(sim_printEnum messageType, kal_uint32 value1, kal_uint32 value2, kal_uint32 value3, kal_uint32 value4, kal_uint32 value5);
extern void DRV_ICC_print_str(kal_char sim_dbg_str[]);
extern void sim_dump_fifo(sim_HW_cb *hw_cb);
extern void sim_MT6306_clkStopper(sim_HW_cb *hw_cb);
extern void SIM_RegHotPlugCb(SIM_ICC_APPLICATION application, DCL_SIM_PLUG_IN_CALLBACK hotPlugInCb, DCL_SIM_PLUG_OUT_CALLBACK hotPlugOutCb);
extern void DRV_ICC_Calc_WWT(kal_uint16 Fi, kal_uint8 Di,  kal_uint8 Wi, kal_uint32 *WWT);
#if defined(SIM_DRV_IC_USB)
extern kal_uint32 SIM_icusb_init(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_setVolt(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_enableSession(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_powerOn(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_cmd(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_disableSession(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_disconnectDone(sim_HW_cb *hw_cb);
extern kal_uint32 SIM_icusb_deinit(sim_HW_cb *hw_cb);
#endif

#endif /*__SIM_DRV_SW_API_H__*/
