#ifndef __SIM_DRV_SW_FUNCTION_H__
#define __SIM_DRV_SW_FUNCTION_H__



#ifdef SIM_DBG_OPTION_ENABLE
#define SIM_ASSERT(_condition) \
   {                             \
      ASSERT(_condition);        \
   }
#else   /*!SIM_DBG_OPTION_ENABLE*/
#if defined(SIM_DEBUG_INFO)
#define SIM_ASSERT(_condition) \
   {                             \
      if (!(_condition))         \
      {                          \
         sim_assert(__LINE__); \
      }                          \
   }
#else   
#define SIM_ASSERT(_condition)
#endif /*#if defined(SIM_DEBUG_INFO)*/
#endif   /*SIM_DBG_OPTION_ENABLE*/

#ifdef NO_SLIM_DEF
#define SIM_SetRXRetry(_RXRetry)\
{\
	kal_uint16 _Retry;\
	_Retry = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);\
	_Retry &= ~SIM_RETRY_RXMASK;\
	_Retry |= _RXRetry;\
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), _Retry);\
}

#define SIM_SetTXRetry(_TXRetry) \
{\
	kal_uint16 	_Retry;\
	_Retry = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK);\
	_Retry &= ~SIM_RETRY_TXMASK;\
	_Retry |= (_TXRetry<<8);\
	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_RETRY_MTK), _Retry);\
}
#endif
#define SIM_ObtainSW(_SW) \
{\
   kal_uint16 _SW1;\
   kal_uint16 _SW2;\
   _SW1 = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW1_MTK);\
   _SW2 = SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_SW2_MTK);\
   _SW = (_SW2 | (_SW1 << 8));\
}

#define SIM_SetIMP3(_IMP3)    SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IMP3_MTK), _IMP3)
#define SIM_SetCmdINS(_INS)   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_INS_MTK), _INS)
#define SIM_SetAtime(_ATIME)  SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_ATIME_MTK), _ATIME)
#define SIM_SetDtime(_DTIME)  SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_DTIME_MTK), _DTIME)
#define SIM_FIFO_Flush()      SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 0x01)

#ifdef NO_SLIM_DEF
#define SIM_Reject_Single() \
{\
   SIM_DisAllIntr();\
   SimCard.State = SIM_PWROFF;\
   *(volatile kal_uint16 *)SIM_IRQEN = SIM_IRQEN_SIMOFF;\
	*(volatile kal_uint16 *)SIM_CTRL &= ~SIM_CTRL_SIMON;\
	SIM_FIFO_Flush();\
}

#define SIM_Reject_MT6302(hw_cb) \
{\
   SIM_DisAllIntr();\
   if (SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)\
   {\
   sim_MT6302_addMsg(SIM_MT6302_DRIVER_DEACT, hw_cb->simInterface, 2, 0);\
      SimCard->State = SIM_PWROFF;\
      SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_SIMOFF);\
      SIM_FIFO_Flush();\
      if(KAL_FALSE == sim_MT6302_QueryNeedManualControl(hw_cb)){\
      SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON);\
      sim_MT6302_VCCCtrl(hw_cb, 0);\
	}\
      	else{\
      		sim_MT6302_manualDeactive(hw_cb);\
      	}\
	}\
	else\
	{\
      sim_PDNEnable_MT6302(hw_cb);\
      if(SimCard->reject_set_event)\
         SIM_SetEvent_MT6302(SimCard,SIM_NOREADY);\
	}\
}

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
#define SIM_Reject_MTK(hw_cb) \
{\
   SIM_DisAllIntr();\
   if (SIM_Reg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK))&SIM_CTRL_SIMON)\
   {\
   sim_addMsg(SIM_DRIVER_DEACT_SIMD, hw_cb->simInterface, 2, 0);\
      SimCard->State = SIM_PWROFF;\
      SIM_WriteReg(SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK, SIM_IRQEN_SIMOFF);\
      SIM_FIFO_Flush();\
      SIM_ClearBits(SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK, SIM_CTRL_SIMON);\
	}\
	else\
	{\
      sim_PDNEnable_MTK(hw_cb);\
      if(SimCard->reject_set_event)\
         SIM_SetEvent_MTK(SimCard,SIM_NOREADY);\
	}\
}
#endif
#define SIM_Active()    SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), 0x0001)

#ifdef NO_SLIM_DEF
#define SIM_WaitEvent_Single(_SIMCARD,_flag) \
{\
   kal_uint32 _event_group;\
   kal_status returnValueOfSIMWaitEvent;\
   extern void sim_dump_error_line(void);\
   returnValueOfSIMWaitEvent = returnValueOfSIMWaitEvent;\
   _SIMCARD.event_state = KAL_TRUE;\
   _SIMCARD.EvtFlag = _flag;\
	returnValueOfSIMWaitEvent = kal_retrieve_eg_events(_SIMCARD.event,_flag,KAL_OR_CONSUME,&_event_group,KAL_SUSPEND);\
	sim_dump_error_line();\
}

#define SIM_SetEvent_Single(_SIMCARD,_result)   \
{\
   kal_status returnValueOfSIMSetEvent;\
   returnValueOfSIMSetEvent = returnValueOfSIMSetEvent;\
   _SIMCARD.result = _result;\
   _SIMCARD.event_state = KAL_FALSE;\
   returnValueOfSIMSetEvent = kal_set_eg_events(_SIMCARD.event,_SIMCARD.EvtFlag,KAL_OR);\
   *(volatile kal_uint16 *)SIM_IRQEN = SIM_IRQEN_ALLOFF;\
}

#define SIM_WaitEvent_MT6302(_SIMCARD,_flag, _unmaskSIMIntr) \
{\
   kal_uint32 _event_group;\
   kal_status returnValue;\
   extern void sim_dump_error_line(void);\
   returnValue = returnValue;\
   _SIMCARD->event_state = KAL_TRUE;\
   _SIMCARD->EvtFlag = _flag;\
   switch_CB->sim_workingTaskWaiting = KAL_TRUE;\
   if(KAL_TRUE == _unmaskSIMIntr)\
   	IRQUnmask(hw_cb->mtk_lisrCode);\
	returnValue= kal_retrieve_eg_events(_SIMCARD->event,_flag,KAL_OR_CONSUME,&_event_group,KAL_SUSPEND);\
	switch_CB->sim_workingTaskWaiting = KAL_FALSE;\
	sim_dump_error_line();\
}

#define SIM_SetEvent_MT6302(_SIMCARD,_result)   \
{\
   _SIMCARD->result = _result;\
   _SIMCARD->event_state = KAL_FALSE;\
   if(0 == _SIMCARD->EvtFlag)\
   	kal_set_eg_events(_SIMCARD->event,SIM_EVT_CMD_END,KAL_OR);\
   else\
   kal_set_eg_events(_SIMCARD->event,_SIMCARD->EvtFlag,KAL_OR);\
   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);\
   sim_MT6302_addMsg(0x12345678, _SIMCARD->EvtFlag, __LINE__, drv_get_current_time());\
}

/*********************************************************************************************
*we move this macro from sim_sw_comm.h to here, since we need a distinguish from dual controllers or MT6302.
*In dual controllers solution, we need to enable interrupt according to simInterface, but in MT6302 solution, we only need to enable SIM's.
**********************************************************************************************/
#define SIM_WaitEvent_MTK(_SIMCARD,_flag, _unmaskSIMIntr) \
{\
   kal_uint32 _event_group;\
   extern void sim_dump_error_line(void);\
   _SIMCARD->event_state = KAL_TRUE;\
   _SIMCARD->EvtFlag = _flag;\
   if(KAL_TRUE == _unmaskSIMIntr){\
   		IRQUnmask(hw_cb->mtk_lisrCode);\
   	}\
	kal_retrieve_eg_events(_SIMCARD->event,_flag,KAL_OR_CONSUME,&_event_group,KAL_SUSPEND);\
	sim_dump_error_line();\
}

//redefine new MACRO since there is no sim_MT6302_addMsg API in MT6235, MT6238 and I don't want to change MT6302 again
#define SIM_SetEvent_MTK(_SIMCARD,_result)   \
{\
   _SIMCARD->result = _result;\
   _SIMCARD->event_state = KAL_FALSE;\
   if(0 == _SIMCARD->EvtFlag)\
   	kal_set_eg_events(_SIMCARD->event,SIM_EVT_CMD_END,KAL_OR);\
   else\
   kal_set_eg_events(_SIMCARD->event,_SIMCARD->EvtFlag,KAL_OR);\
   SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF);\
   sim_addMsg(0x12345678, _SIMCARD->EvtFlag, __LINE__, drv_get_current_time());\
}
#endif
#define SIM_NotifyCARDisHALTEN()       SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HALTEN)
#define SIM_T0CtrlEnable()             SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T0EN)
#define SIM_T0CtrlDisable()            SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T0EN)
#define SIM_FlowCtrlEnable()             SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HFEN)
#define SIM_FlowCtrlDisable()            SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_HFEN)

#define SIM_DisIntr(_Intr)            SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), _Intr)


#ifdef __OLD_PDN_ARCH__
#define sim_PDNEnable_Single()	DRVPDN_Enable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM)
#define sim_PDNDisable_Single()	DRVPDN_Disable(DRVPDN_CON1,DRVPDN_CON1_SIM,PDN_SIM)
#else
#if defined (LPWR_SLIM)
#define sim_PDNEnable_Single()	\
	if (hw_cb->mtk_pdnDevice == PDN_DEV_SIM) \
		PDN_SET(PDN_SIM); \
	else	\
	   PDN_SET(PDN_SIM2); \
	L1SM_SleepEnable(hw_cb->smHandler);  
#define sim_PDNDisable_Single()	\
	if (hw_cb->mtk_pdnDevice == PDN_DEV_SIM) \
		PDN_CLR(PDN_SIM); \
	else	\
		PDN_CLR(PDN_SIM2); \
	L1SM_SleepDisable(hw_cb->smHandler);
#else
#define sim_PDNEnable_Single()	DRVPDN_Enable(PDN_SIM)
#define sim_PDNDisable_Single()	DRVPDN_Disable(PDN_SIM)
#endif
#endif




#define SIM_ActiveClk_Single()       \
{\
   sim_PDNDisable_Single();\
   *(volatile kal_uint16 *)SIM_CTRL &= ~SIM_CTRL_HALT;\
}

#define SIM_ActiveClk_MT6302(hw_cb)       \
{\
   sim_PDNDisable_MT6302(hw_cb);\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
}

#define SIM_ActiveClk_MT6306(hw_cb)       \
{\
   sim_PDNDisable_MT6306(hw_cb);\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
}

#define SIM_ActiveClk_MTK(hw_cb)       \
{\
   sim_PDNDisable_MTK(hw_cb);\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
}

#define SIM_Idle_Single(_level)   \
{\
	if (_level == KAL_TRUE)\
	{\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	else\
	{\
	    SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
	    SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	sim_PDNEnable_Single();\
}

#define SIM_Idle_MT6302(_level, hw_cb)   \
{\
	if (_level == KAL_TRUE)\
	{\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	else\
	{\
	    SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
	    SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	sim_PDNEnable_MT6302(hw_cb);\
}

#define SIM_Idle_MT6306(_level, hw_cb)   \
{\
	if (_level == KAL_TRUE)\
	{\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	else\
	{\
	    SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
	    SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	sim_PDNEnable_MT6306(hw_cb);\
}

#define SIM_Idle_MTK(_level, hw_cb)   \
{\
	if (_level == KAL_TRUE)\
	{\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
		SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	else\
	{\
	    SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_CLKPO);\
	    SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_HALT);\
	}\
	sim_PDNEnable_MTK(hw_cb);\
}

#define SIM_FIFO_GetLev()  (SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK) & SIM_COUNT_MASK)
#define SIM_DisTOUTIntr()  SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_TOUT)
#define SIM_OpenTOUTIntr()  SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_TOUT)
#define SIM_DisAllIntr()    SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_IRQEN_MTK), SIM_IRQEN_ALLOFF)

#ifdef NO_SLIM_DEF

#ifdef SIM_TOUT_REG_V2
#ifdef SIM_TOUT_REG_V3
#define SIM_SetTOUT(_TOUT)    \
{\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
   if (_TOUT < 0xffffff)\
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), ((_TOUT)/4));\
   else\
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffffff);\
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);\
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
}
#else
#define SIM_SetTOUT(_TOUT)    \
{\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
   if (_TOUT < 0xffffff)\
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), _TOUT);\
   else\
   	SIM_WriteReg32((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffffff);\
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);\
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
}
#endif
#else
#define SIM_SetTOUT(_TOUT)    \
{\
   SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
   if (_TOUT < 0xffff)\
   	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), _TOUT);\
   else\
   	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TOUT_MTK), 0xffff);\
   SIM_Reg(SIM0_BASE_ADDR_MTK + SIM_STS_MTK);\
   SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN);\
}
#endif
#endif /* End of #ifdef NO_SLIM_DEF */
#ifdef NoT0CTRL
#define SIMCmdInit()
#else /*NoT0CTRL*/
#define SIMCmdInit() \
{\
   SIM_T0CtrlEnable(); /*SIM_FlowCtrlEnable()*/ \
}
#endif   /*NoT0CTRL*/

// macros
#define SIM_WARM_RST()		SIM_SetBits((SIM0_BASE_ADDR_MTK +SIM_CTRL_MTK), SIM_CTRL_WRST)

/*
	normally, wait event will before set event, but sometimes set event will before wait event.
	for instance, during wait event, an interrupt is generated and trigger another interrupt before
	the corresponding wait event.
*/

#define USIM_CLR_EVENT_Single()\
	kal_set_eg_events(usim_dcb.event,0,KAL_AND)

#define USIM_CLR_EVENT_Multiple()\
	kal_set_eg_events(usim_dcb->event,0,KAL_AND)

#define USIM_POW_ON() SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), SIM_CTRL_SIMON)
#define USIM_WRST()	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_CTRL_MTK), (SIM_CTRL_WRST|SIM_CTRL_SIMON))
#define USIM_ENABLE_T0()	SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T0EN)
#define USIM_ENABLE_T1()	SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T1EN)
#define USIM_DISABLE_T1()	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_T1EN)
#define USIM_ENABLE_TXRX_HANSHAKE()	SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), (SIM_CONF_TXHSK|SIM_CONF_RXHSK))
#define USIM_DISABLE_TXRX_HANSHAKE()	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), (SIM_CONF_TXHSK|SIM_CONF_RXHSK))
#define USIM_TX_START_T1()	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_INS_MTK), 1)

#define USIM_IS_IBLOCK(pcb)	((pcb&PCB_I_BIT8)==0)
#define USIM_IS_RBLOCK(pcb)	((pcb&PCB_R_DEFAULT) == 0x80)
#define USIM_IS_SBLOCK(pcb)	((pcb&PCB_S_DEFAULT) == PCB_S_DEFAULT)
#define USIM_IS_RESP(pcb)		(pcb&PCB_S_RESP)
#define USIM_INV_N(n)	(n = (n)?0:PCB_I_SEQ)
#define USIM_CLR_FIFO()	SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_COUNT_MTK), 1)
#define USIM_RESET_T1()	USIM_DISABLE_T1();USIM_ENABLE_T1();
#define USIM_ENABLE_TOUT()	SIM_SetBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), SIM_CONF_TOUTEN)
#define USIM_DISABLE_TOUT()	SIM_ClearBits((SIM0_BASE_ADDR_MTK + SIM_CONF_MTK), (SIM_CONF_TOUTEN))
//#define USIM_CLR_TX_TIDE()		SIM_Reg(SIM_TIDE)&=(~SIM_TIDE_TXMASK)
#define USIM_DMA_RX_TIDE()			SIM_WriteReg((SIM0_BASE_ADDR_MTK + SIM_TIDE_MTK), 0);
#define USIM_CAL_TD_COUNT(a,b)	\
		{\
			if(a & TAMask) b++;\
   		if(a & TBMask) b++;\
   		if(a & TCMask) b++;\
   	}

// generate R-block header
#define USIM_MAKE_R_BLOCK_Single(e)	\
		{\
			kal_uint8 pcbInMacroMakeRBlock;\
\
			if(usim_dcb.nr)\
				pcbInMacroMakeRBlock = (PCB_R_N1|e);\
			else\
				pcbInMacroMakeRBlock = (PCB_R_N0|e);\
			usim_dcb.header_tx[T1_PCB_INDEX] = pcbInMacroMakeRBlock;\
			usim_dcb.header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb.cmd_state = R_BLOCK_TX;\
		}

#define USIM_MAKE_S_RESYNC_Single()\
{\
			usim_dcb.header_tx[T1_PCB_INDEX] = PCB_S_DEFAULT;\
			usim_dcb.header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb.cmd_state = S_BlOCK_REQ_TX;\
}

#define USIM_MAKE_R_BLOCK_Multiple(e)	\
		{\
			kal_uint8 pcb;\
\
			if(usim_dcb->nr)\
				pcb = (PCB_R_N1|e);\
			else\
				pcb = (PCB_R_N0|e);\
			usim_dcb->header_tx[T1_PCB_INDEX] = pcb;\
			usim_dcb->header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb->cmd_state = R_BLOCK_TX;\
		}

#define USIM_MAKE_S_RESYNC_Multiple()\
{\
			usim_dcb->header_tx[T1_PCB_INDEX] = PCB_S_DEFAULT;\
			usim_dcb->header_tx[T1_LEN_INDEX] = 0;\
			usim_dcb->cmd_state = S_BlOCK_REQ_TX;\
}


////////////// temp definitions///////////////
#define error()
//////////////////////////////////////////////

/*following is to move control block resource control code to custom files*/
extern void *sim_get_sim_cb(kal_uint32 tasakInterface);
extern void *sim_get_usim_cb(kal_uint32 tasakInterface);
#define GET_USIM_CB(a) sim_get_usim_cb(a)
#define GET_SIM_CB(a) sim_get_sim_cb(a)

#define IMPLEMENTING_ASSERT	ASSERT(0)

#define sim_print(a,b)		dbg_print(a,b)
//#define sim_print(a,b)	kal_prompt_trace(MOD_SIM,a,b)

#if defined(USIM_DEBUG)
#define USIM_WAIT_EVENT_Single() \
{\
	usim_dcb.wline[(usim_dcb.windex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("wait event at line:%d\r\n",__LINE__);\
	usim_dcb.windex++;\
	DRV_ICC_GPTI_StartItem(usim_dcb.gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  NULL);\
	kal_retrieve_eg_events(usim_dcb.event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb.ev_flag,KAL_SUSPEND);\
	if(usim_dcb.status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb.gpt_handle);	\
}
#define USIM_SET_EVENT_Single()\
{\
	usim_dcb.sline[(usim_dcb.sindex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("set event at line:%d\r\n",__LINE__);\
	usim_dcb.sindex++;\
	kal_set_eg_events(usim_dcb.event,USIM_EVENT,KAL_OR);\
}

#define USIM_WAIT_EVENT_MT6302() \
{\
	usim_dcb->wline[(usim_dcb->windex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("wait event at line:%d\r\n",__LINE__);\
	usim_dcb->windex++;\
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  usim_dcb);\
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);\
	if(usim_dcb->status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	\
}
#define USIM_WAIT_EVENT_MTK() \
{\
	usim_dcb->wline[(usim_dcb->windex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("wait event at line:%d\r\n",__LINE__);\
	usim_dcb->windex++;\
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  usim_dcb);\
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);\
	if(usim_dcb->status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	\
}

#define USIM_SET_EVENT_Multiple()\
{\
	usim_dcb->sline[(usim_dcb->sindex&(INDEX_COUNT-1))] = __LINE__;\
	dbg_print("set event at line:%d\r\n",__LINE__);\
	usim_dcb->sindex++;\
	kal_set_eg_events(usim_dcb->event,USIM_EVENT,KAL_OR);\
}
#else
#ifdef NO_SLIM_DEF

#define USIM_WAIT_EVENT_Single()\
{\
	DRV_ICC_GPTI_StartItem(usim_dcb.gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  NULL);\
	kal_retrieve_eg_events(usim_dcb.event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb.ev_flag,KAL_SUSPEND);\
	if(usim_dcb.status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb.gpt_handle);	\
}
#define USIM_SET_EVENT_Single()\
	kal_set_eg_events(usim_dcb.event,USIM_EVENT,KAL_OR)

#define USIM_WAIT_EVENT_MT6302()\
{\
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  usim_dcb);\
       switch_CB->sim_workingTaskWaiting = KAL_TRUE;\
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);\
	switch_CB->sim_workingTaskWaiting = KAL_FALSE;\
	if(usim_dcb->status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	\
}

#define USIM_WAIT_EVENT_MT6306()\
{\
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  usim_dcb);\
       switch_CB->sim_workingTaskWaiting = KAL_TRUE;\
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);\
	switch_CB->sim_workingTaskWaiting = KAL_FALSE;\
	if(usim_dcb->status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	\
}


#define USIM_WAIT_EVENT_MTK()\
{\
	DRV_ICC_GPTI_StartItem(usim_dcb->gpt_handle,\
                  USIM_GPT_TIMEOUT_PERIOD,\
                  usim_gpt_timeout_handler,\
                  usim_dcb);\
	kal_retrieve_eg_events(usim_dcb->event,USIM_EVENT,KAL_AND_CONSUME,&usim_dcb->ev_flag,KAL_SUSPEND);\
	if(usim_dcb->status != USIM_GPT_TIMEOUT)\
		DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);	\
}

#define USIM_SET_EVENT_Multiple()\
{\
	DRV_ICC_GPTI_StopItem(usim_dcb->gpt_handle);\
	kal_set_eg_events(usim_dcb->event,USIM_EVENT,KAL_OR);\
}
#endif /* End of #ifdef NO_SLIM_DEF */
#endif


#endif /*__SIM_DRV_SW_FUNCTION_H__*/
