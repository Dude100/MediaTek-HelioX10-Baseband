#ifndef __SIM_DRV_SW_STRUCT_H__
#define __SIM_DRV_SW_STRUCT_H__

#define SIM_HW_CB_HEAD 0x5A5A5A5A
#define SIM_HW_CB_TAIL 0xA5A5A5A5

/* For sim hot plug callback function */
#include "dcl.h"
//typedef void (*DCL_SIM_PLUG_OUT_CALLBACK)(kal_uint32 simIf);
//typedef void (*DCL_SIM_PLUG_IN_CALLBACK)(kal_uint32 simIf);

/*Only for MT6290 HDMA structure*/
#if defined(DRV_SIM_6290_SERIES)

typedef struct{
    kal_uint32 BURST_SIZE;
    kal_uint32 MEM_BUS_WIDTH;
    kal_uint32 DEV_BUS_WIDTH;
    kal_uint32 channel;             // two channels(0 or 1) are avaliable in MT6290
    //DMA config register address
    kal_uint32 ADDR_HDMA_HPRGA0Rx;  //buf 0 : used for TX or RX 
    kal_uint32 ADDR_HDMA_HPRGA1Rx;  //buf 1: used for RX in auto-switch
    kal_uint32 ADDR_HDMA_HDCTRRx;   //config for buf direction, burst size, dev bus width, and mem bus width
    kal_uint32 ADDR_HDMA_HDC0Rx;    //buf 0 config for transfer size and start
    kal_uint32 ADDR_HDMA_HDC1Rx;    //buf 1 config for transfer size and start
}Sim_HDMA_struct;

#endif

typedef struct{
	kal_uint32	head;
	/*
		Here defines MTK related HW information of this logical interface, these values are defined as constant in old driver.
		Now we make it variable.
	*/
	kal_uint32	mtk_baseAddr;
#if !defined(DRV_SIM_6290_SERIES)
	kal_uint32	mtk_pdnAddr;
	kal_uint32	mtk_pdnBit;
	kal_uint32	mtk_pdnDevice;
	kal_uint32	mtk_dmaMaster;
#endif
	kal_uint32	mtk_lisrCode;
	/*
		in multiple SIM drivers, simInterface is used in all most all functions, we need record this information.
	*/
	kal_uint32	simInterface; /*The logical number. This value now can be 0~n, not limted as 0~1 before. We can assume it less than 2 now*/
	kal_uint32	MT6302ChipNo;	/*record which MT6302 switch used for this card*/
	kal_uint32	MT6302PortNo; 		/*record which port of MT6302 is used for this card*/
	void			*MT6302PeerInterfaceCb;/*MT6302 need peer's information, so we have to maintain a way to find its peer*/
	kal_uint32  simSwitchChipNo;
	kal_uint32  simSwitchPortNo;
	void        *simSwitchPeerInterfaceCb;
	void        *simSwitchPeerInterfaceCb1;
	void        *simSwitchPeerInterfaceCb2;
	DCL_SIM_PLUG_IN_CALLBACK simHotPlugIn;
	DCL_SIM_PLUG_OUT_CALLBACK simHotPlugOut;
	kal_uint32 debounceTime; /* hot swap EINT debounce time */
	kal_uint32	tail;
	kal_bool polarity; /* hot swap EINT poarity */	
	kal_bool	IsCardRemove;	
	kal_uint8 smHandler;
}sim_HW_cb;

typedef struct {
	kal_uint32* ptr;
	kal_uint32 size;
}sim_nvram_param_struct;

typedef struct{
	sim_power_enum power;
	sim_speed_enum speed;
	sim_clock_stop_enum clock_stop;
	sim_protocol_app_enum app_proto;
	sim_protocol_phy_enum phy_proto;
	kal_bool T0_support;	// if T0 is supported
	kal_bool T1_support;	// if T1 is supported
	kal_uint8 hist_index; // index to the historical char of ATR
	kal_uint8 *ATR;
	/*following information is necessary for SIM task for UICC identification*/
	kal_bool TAiExist; //if the first TA for T=15 is existed
	kal_uint8 ATR_length;			// length to the ATR_data
    kal_bool isSW6263; // query if status word 0x62xx 0x63xx happen
}sim_info_struct;

#if defined SIM_DRV_IC_USB
typedef struct{
    kal_uint8 *txData;
    kal_uint16 txSize;
    kal_uint8 *result;
    kal_uint16 *rcvSize;
    kal_uint16  *sw;
}sim_icusb_T0cmd;

typedef struct{
    kal_uint8 sif;
    kal_uint8 pcb;
    kal_uint16 cp;
    kal_uint16 len;
    kal_uint8 *apdubuf;
}sim_icusb_message;
#endif


typedef struct
{
	kal_uint8    State;
	kal_uint8    Data_format;      /*SIM_direct,SIM_indirect*/
	kal_uint8    Power;            /*SIM_3V,SIM_5V*/
	kal_uint8    recData[40];     /*PTS or ATR data*/
	kal_bool     recDataErr;
	kal_uint8    result;           /* for ATR, command, RST   */
	sim_env      SIM_ENV;
#ifndef SIM_ADDDMA
	kal_uint8    *txbuffer;        /* only used for no DMA */
	kal_uint16   txsize;           /* only used for no DMA */
	kal_uint16   txindex;          /* only used for no DMA */
	kal_uint8    *rxbuffer;        /* only used for no DMA */
#ifdef   NoT0CTRL
   kal_uint8    INS;
   kal_uint8    SW1;
   kal_uint8    SW2;
   kal_uint16   recsize;
#endif	/*NoT0CTRL*/
#endif   /*SIM_ADDDMA*/
/*add for clock stop mode*/
   kal_uint8    cmdState;         /* only used for no T0CTRL, and for clock stop */
   kal_uint8    Speed;            /*Speed372,Speed64,Speed32*/
   kal_bool     clkStop;          /*Clok Stop Enable*/
   kal_bool     clkStopLevel;     /*Clok Stop level*/
   kal_bool     reject_set_event;
   kal_bool     event_state;
   kal_uint8    initialPower;
   sim_card_speed_type  sim_card_speed;
	kal_hisrid        hisr;             /*SIM HISR*/
  	kal_eventgrpid    event;      /*SIM Event*/

  	sim_protocol_app_enum app_proto;
  	kal_bool 	timeout;
  	usim_cmd_case_enum cmd_case;
	kal_bool 	is_err;	// sim command has error once.
	kal_bool	get9000WhenSelect;

	/*
		following variables are get from global variables for 2 SIM projects.
		We won't use these in single SIM driver, but we need to define the power set.
	*/
  	kal_uint8			TOUT_Factor;
#if defined(DRV_SIM_6290_SERIES)
    kal_uint16 Fi;
    kal_uint16 etu_of_1860;
	kal_uint16 etu_of_700;
#endif
    
  	kal_uint8			reset_index;
#ifdef SIM_ADDDMA
    #if defined(DRV_SIM_6290_SERIES)
        Sim_HDMA_struct     dma_config;
    #else
        kal_uint8			sim_dmaport;
  	    DMA_HWMENU	        sim_menu;
  	    DMA_INPUT		    sim_input;
    #endif
#endif
  	kal_bool			TS_HSK_ENABLE;
  	kal_bool			sim_ATR_fail;
  	kal_bool			PTS_check;    /*if false use default value: F=372, D=1*/
  	kal_uint8			PTS_data[4];
	kal_uint8		sim_nullByteIssueNullCount;
	kal_uint32		sim_nullByteIssuenonNullCount;
	kal_bool		keepAtrFatal;
	kal_uint16   recDataLen;       /* for command, ATR process   */
	kal_uint32   EvtFlag;
  	kal_uint32		TOUTValue;
	kal_uint32		sim_nullByteIssueGPT;

/*
	magic1 is an increasing counter, increases when 1) start new command, 2)get SIM timeout, 3)get T0 end
	for case 2 and 3, it means that one of the ends of SIM commands has appeared.
*/
	kal_uint32	simMagic1;
/*
	magic2 is used to compared with magic1 every time GPT expires. It is set to magic1 in the start of a new command,
	if they were compared equally in GPT timer, we know that we are still waiting for SIM controller's event.
*/
	kal_uint32	simMagic2;
	kal_uint32 gpt_handle;
	kal_bool	   clkstoping;
	sim_power_enum power_class;		// supported power class indicated at ATR	[patch from 6280 sim driver]
	kal_bool TC2Present;
	kal_uint32 previous_state;
	kal_uint32 atr_count;
#if defined(SIM_DRV_IC_USB)
    kal_bool isIcUsb; // query if support ic usb
    kal_uint8 TB15; // query if support ic usb 	
    kal_bool isIcUsbRecPPS; // query if support ic usb PPS resp received
    kal_uint32 uart_sim_ccci_handle;
    usim_icusb_state_enum icusb_state;
    sim_icusb_T0cmd sim_icusb_T0cmd;
    kal_uint8    icusb_recData[40];     /*PTS or ATR data*/	
    kal_bool isPrefer3V;			// prefer3v
    kal_uint32 waitingTime;			// waitingTime
	kal_bool forceISO;
#endif
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
	kal_bool poll_sim_2s;
#endif
}Sim_Card;



typedef struct{
	usim_dir_enum dir;

}ATR_struct;

// specify the supported attributes  of the UICC
typedef struct{
	usim_power_enum power;
	usim_protocol_enum protocol;
	usim_clock_stop_enum clock_stop;
	usim_speed_enum speed;
}usim_info_struct;

typedef struct{
	// before reset
	kal_bool high_speed_en;		// control if high speed is enalbed
	usim_power_enum power_in;		// expected power class input form application layer
	// after reset
	usim_clock_stop_enum clock_stop_type;
}usim_config_struct;

typedef struct
{
	kal_eventgrpid event;
	usim_power_enum power;			// power class used
	usim_status_enum status;
	usim_speed_enum speed;		// speed selected
	// state control
	volatile usim_main_state_enum main_state;
	volatile usim_status_enum ev_status;
	// informations
	usim_dir_enum dir;	// convention of character frame
  	sim_protocol_app_enum app_proto;	// application protocol (USIM, SIM)
  	sim_protocol_phy_enum phy_proto; // protocol type selected (physical layer)

	// ATR info
	kal_uint8 ATR_data[36];		// used to store all ATR data string
	kal_uint8 ATR_index;			// index to the ATR_data
	kal_uint8 header_tx[4], header_tx_bak[4]; // header_tx_bak used to backup the previous command
	kal_uint8 header_rx[4];
	kal_uint8 dma_buffer[USIM_DMA_MAX_SIZE];
	kal_uint8 retry;

	sim_env sim_env;		// the voltage which MS can supply
	usim_power_enum power_in;		// expected power class input form application layer
	usim_power_enum power_class;		// supported power class indicated at ATR
	kal_bool	clock_stop_en;		// clock_stop is enabled or not
	// usim_protocol_enum T;
	usim_speed_enum card_speed; // TA1, max speed card can support
	kal_bool high_speed_en;		// control if high speed is enalbed
	usim_clock_stop_enum clock_stop_type;
	kal_bool present;
	usim_reset_type_enum reset_mode; // specific or negotiable mode
	kal_bool warm_rst;	// KAL_TRUE: it's a warm reset, KAL_FALSE: a cold reset
	kal_bool T0_support;	// if T0 is supported
	kal_bool T1_support;	// if T1 is supported
	kal_uint8 Di;


	// T=1
	kal_uint8 ns;		// sequence # of sending
	kal_uint8 nr;		// sequence # of receiving
	kal_uint8 ifsd;	// information size of interface device
	kal_uint8 ifsc;	// information size of card
	usim_cmd_state_enum cmd_state;
	usim_cmd_state_enum cmd_state_bak;
	kal_bool abort;
	kal_bool wtx;	// waiting time extension
	kal_bool resync;
  	kal_bool send_prev;	// send the previous block
	kal_bool tx_chain;
	kal_bool rx_chain;
	kal_uint8 *tx_buf;
	kal_uint8 *rx_buf;
	kal_uint8 sw[2];		// used to contain SW1 and SW2
	kal_uint8 wtx_m;		// multiplier of BWT

	// others
	kal_bool ts_hsk_en;	// enable handshake at TS byte (error signal and char repetition)
	
    #ifdef SIM_ADDDMA
      #if defined(DRV_SIM_6290_SERIES)
        Sim_HDMA_struct     dma_config;
      #else
        kal_uint8			dma_port;
  	    DMA_HWMENU	        dma_menu;
  	    DMA_INPUT		    dma_input;
      #endif
    #endif
  	kal_uint8 hist_index;		// index to the historical characters
  	usim_cmd_case_enum cmd_case;
	sim_protocol_phy_enum perfer_phy_proto; // protocol type selected (physical layer)
	/*SIM task need following information for UICC identification*/
	kal_bool TAiExist; //if the first TA for T=15 is existed

#if defined(USIM_DEBUG)
	kal_int32 sline[INDEX_COUNT];	// set event at the which line in usim_drv.c
	kal_uint32 sindex;	// index to the sline[4]
	kal_int32 wline[INDEX_COUNT];	// wait event at the which line in usim_drv.c
	kal_uint32 windex;	// index to the wline
#endif
	kal_uint16 tx_size;
	kal_uint16 rx_size;
	kal_uint16 tx_index;
	kal_uint16 rx_index;

	kal_uint16 Fi;
	kal_uint16 etu_of_1860;
	kal_uint16 etu_of_700;
	kal_uint32 gpt_handle;

	// time out control
	kal_uint32 WWT;	// work waiting time (T0)
	kal_uint32 CWT;	// character waiting time in etu(T1)
	kal_uint32 BWT;	// blcok waiting time in etu(T1)
	kal_uint32 timeout;	// etu
	kal_uint32 ev_flag;
	kal_hisrid hisr;
	kal_uint32 int_status;

	/*
		following variables are get from global variables for 2 SIM projects.
		We won't use these in single SIM driver, but we need to define the power set.
	*/
	kal_taskid ownerTask;// the task that own this control block

	kal_uint32 processingState;//to to reentry check
    kal_bool isSW6263; // query if status word 0x62xx 0x63xx happen
	kal_uint32 previous_state;
	kal_uint32 atr_count;
#if defined (SIM_AUTO_TEST)
	kal_bool auto_test; // auto test for MTK internal
#endif
	kal_uint32 intsta[10];
	kal_uint32 intcnt;
#if defined(SIM_DRV_IC_USB)
    kal_bool isIcUsb; // query if support ic usb
    kal_uint8 TB15; // query if support ic usb    
    kal_bool isIcUsbRecPPS; // query if support ic usb PPS resp received
    kal_uint32 uart_sim_ccci_handle;    
    usim_icusb_state_enum icusb_state;
    kal_uint8 icusb_ATR_data[36];		// used to store all ATR data string
    kal_uint8 icusb_ATR_index;			// index to the ATR_data	
    kal_bool isPrefer3V;			// prefer3v
    kal_uint32 waitingTime;			// waitingTime
	kal_bool forceISO;
#endif	
#if defined(__SIM_HOT_SWAP_POLL_TIMER__) && defined(__SIM_HOT_SWAP_SUPPORT__)
	kal_bool poll_sim_2s;
#endif
}usim_dcb_struct;

extern usim_dcb_struct usim_dcb;


typedef struct{
	sim_msgTag					tag;
	kal_uint32					event;
	kal_uint32					data1;
	kal_uint32					data2;
	kal_uint32					time;
}sim_msg;

typedef usim_status_enum  (*SIM_API_RESET) (sim_power_enum ExpectVolt, sim_power_enum *ResultVolt, kal_bool warm, sim_HW_cb *hw_cb);
typedef sim_status (*SIM_API_CMD) (kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, sim_HW_cb *hw_cb);
typedef void (*SIM_API_PWROFF) (sim_HW_cb *hw_cb);
typedef void (*SIM_API_CARDINFO) (sim_info_struct *info, sim_HW_cb *hw_cb);
typedef void (*SIM_API_ENHANCED_SPEED) (kal_bool enable, sim_HW_cb *hw_cb);
typedef void (*SIM_API_ENHANCED_SELECT_PHY) (sim_protocol_phy_enum T, sim_HW_cb *hw_cb);
typedef kal_bool (*SIM_API_SET_CLKSTOP) (sim_clock_stop_enum mode, sim_HW_cb *hw_cb);
typedef void (*SIM_API_EOC) (sim_HW_cb *hw_cb);
typedef void (*SIM_API_MSG)(kal_uint32 tag, kal_uint32 event, kal_uint32 data1, kal_uint32 data2);
typedef void (*SIM_API_TOUT_TEST)(kal_uint32 toutValue, sim_HW_cb *hw_cb);


typedef struct
{
	SIM_API_RESET reset;
	SIM_API_CMD command;
	SIM_API_PWROFF powerOff;
	SIM_API_CARDINFO getCardInfo;
	SIM_API_ENHANCED_SPEED enableEnhancedSpeed;
	SIM_API_ENHANCED_SELECT_PHY selectPreferPhyLayer;
	SIM_API_SET_CLKSTOP setClockStopMode;
	SIM_API_EOC EOC;/*use this to hook necessary action before return to SIM task, this is called by adaption layer, not SIM task*/
	SIM_API_MSG addMessage;
	SIM_API_TOUT_TEST toutTest;
}sim_ctrlDriver;
#if defined(__CGLA__) && defined(MT6752) && defined(__CCCIRPC_SUPPORT__)
/*
typedef struct
{
	kal_bool lock_vsim1;
} sim_nfc_communication;
*/
#endif
#endif /*__SIM_DRV_SW_STRUCT_H__*/
