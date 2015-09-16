#ifndef __SIM_DRV_HW_DEF_MTK_H__
#define __SIM_DRV_HW_DEF_MTK_H__


/* SIM_ADDDMA & NoT0CTRL can't active concurrently */
#define  SIM_ADDDMA

/* SIM Format */
#define SIM_direct      0
#define SIM_indirect    1

/* SIM Power */
#define SIM_30V          RESET_30V
#define SIM_18V          RESET_18V

#define CMD_RECBUFSIZE  13
/*DMA setting, such usb*/
/* Size = 8bit, sinc en, dinc disable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
#define DMA_CON_SimTxNormal   0x0074
/* Size = 8bit, sinc disable, dinc enable, hw management, 1 trans/dma cycle, USB master,Interrupt disable */
#define DMA_CON_SimRxNormal   0x0078

/* SIM State   */
#define  SIM_WAIT_FOR_ATR     0       /* reset SIM card and wait ATR */
#define 	SIM_PROCESS_ATR      1        /* receiving ATR data */
#define 	SIM_PROCESS_PTS      2        /* receiving PTS response data */
#define 	SIM_PROCESSCMD       3
#define 	SIM_SERIOUSERR       4        /* serous error due to txerr*/
#define  SIM_PWROFF           5
#define  SIM_WaitRejectDone   6


/* SIM Miner State   */
#ifdef NoT0CTRL
#define SIMD_CmdIdle          0
#define SIM_WaitProcByte      1
#define SIM_AckDataState      2
#define SIM_NAckDataState     3
#define SIM_WaitSWByte        4
#endif /*NoT0CTRL*/
   /*just for clock stop mode*/
#define SIM_ProcessClk        5
#define SIM_StopClk           6
#define SIM_WaitCmdEnd        7


/* Event */
#define  ATR_END		   0x0100
#define  PTS_END		   0x0008
//#ifdef DCL_SIM_INTERFACE
#define  SIM_EVT_CMD_END	      0x0004
//#else
//#define  CMD_END	      0x0004
//#endif
#define  RST_READY	   0x0002
#define  CLK_PROC       0x0020
#define  ACTIVATE_DONE	0x0040
#define  DEACTIVATE_DONE	0x0080
#define  SWRST_INT_END	0x0100



/*#define INIRET		0x0001*/

/*ATR data define*/
#define TAMask		0x0010
#define TBMask		0x0020
#define TCMask		0x0040
#define TDMask		0x0080

/* Result */
#define SIM_SUCCESS              SIM_NO_ERROR
#define SIM_NOREADY              SIM_NO_INSERT
#define SIM_CARDERR              SIM_CARD_ERROR
#define SIM_INITXERR             5
#define SIM_INIPTSERR            6
#define SIM_CMDTXERR             7  /* parity error */
#define SIM_CMDRECERR            8
#define SIM_CMDTOUT              9
#define SIM_CLKPROC              10
#define SIM_NULLTIMEOUT	11
#define SIM_TS_INVALID           12
#define SIM_NO_ATR               13
#define SIM_RX_INVALID	         14
#define SIM_SWRST	               15
#define SIM_CLKSTOP	            16
#define SIM_GPT_TIMEOUT	         17




#define SW1_GET_RESP_SIM			0x9f
#define SW1_SIM_WARN1			   0x9e
#define SW1_GET_RESP_USIM			0x61
#define SW1_RESEND_USIM				0x6c
#define LEN_INDEX						4		// index to the P3 of command header
#define LEN_OF_CMD					5
#define GET_RESP_CLA_SIM			0xa0
#define GET_RESP_CLA_USIM			0x00
#define SW1_WARN1						0x62
#define SW1_WARN2						0x63
//#ifdef DCL_SIM_INTERFACE
#define SIM_SW_STATUS_OK						0x9000
#define SIM_SW_STATUS_FAIL					0x00
//#else
//#define STATUS_OK						0x9000
//#define STATUS_FAIL					0x00
//#endif

#define Speed372                 0
#define Speed64                  1
#define Speed32                  2
#define Speed16                  3
#define Speed8                  4

typedef kal_uint16 sim_status;

#define MAX_SIM_ERROR_LINE           4



typedef enum
{
	SIM_PROTOCOL,
	USIM_PROTOCOL
}sim_protocol_app_enum;

typedef enum
{
	T0_PROTOCOL,
	T1_PROTOCOL,
	UNKNOWN_PROTOCOL
}sim_protocol_phy_enum;

typedef enum{
	UNKNOWN_POWER_CLASS = 0,
	CLASS_A_50V = 1,
	CLASS_B_30V = 2,
	CLASS_AB 	= 3,
	CLASS_C_18V = 4,
	ClASS_BC		= 6,
	CLASS_ABC	= 7,
	CLASS_12v   = 8,
	CLASS_ALLSUPPORT = 0xff
}sim_power_enum;

typedef enum{
	CLOCK_STOP_NOT_SUPPORT 	= 0x0,
	CLOCK_STOP_LOW 			= 0x40,
	CLOCK_STOP_HIGH 			= 0x80,
	CLOCK_STOP_ANY				= 0xc0,
	CLOCK_STOP_MSK				= 0xc0,
	CLOCK_STOP_UNKONW			= 0x0f
}sim_clock_stop_enum;

typedef enum{
	SPEED_372,
	SPEED_64,
	SPEED_32,
	SPEED_16,
	SPEED_8,
	SPEED_MAX
}sim_speed_enum;

typedef enum{
	SIM_DIRECT,
	SIM_INVERSE
}sim_dir_enum;

typedef enum{
	usim_case_1 = 1,
	usim_case_2,
	usim_case_3,
	usim_case_4
}usim_cmd_case_enum;

typedef enum{
	USIM_DIRECT,
	USIM_INVERSE
}usim_dir_enum;

typedef enum{
	PPSS = 0,	// initial character 0xFF
	PPS0 = 1,	// format character 0x1x
	PPS1 = 2,	// indicate the baudrate F, D
	PCK  = 3,	// exclusive-or PPSS to PCK should be null
	PPS_LEN = 4
}usim_pts_enum;

#define usim_protocol_enum 		sim_protocol_phy_enum
#define usim_speed_enum				sim_speed_enum
#define usim_clock_stop_enum 		sim_clock_stop_enum
#define usim_power_enum 			sim_power_enum

typedef enum{
	ERR_INVALID_BLOCK,
	ERR_TIMEOUT
}usim_err_enum;

typedef enum{
	USIM_RESET_NEGOTIABLE,	// type 1
	USIM_RESET_SPECIFIC		// type 2
}usim_reset_type_enum;

typedef enum{
	IDLE_STATE,
	ACTIVATION_STATE,
	ATR_STATE,
	PTS_STATE,
	MAIN_CMD_READY_STATE,
	CMD_TX_STATE,
	//CMD_RX_HEADER_STATE,
	CMD_RX_BLOCK_REC_STATE,
	//CMD_RX_S_BLOCK_STATE,
	CMD_RX_STATE,
	CLK_STOPPING_STATE,
	CLK_STOPPED_STATE,
	DEACTIVATION_STATE
}usim_main_state_enum;

typedef enum{
	EVENT_TX = 		0x1,
	EVENT_RX = 		0x2,
	EVENT_OV = 		0x4,
	EVENT_TOUT = 	0x8,
	EVENT_TXERR = 	0x10,
	EVENT_NATR = 	0x20,
	EVENT_OFF = 	0x40,
	EVENT_T0END = 	0x80,
	EVENT_RXERR = 	0x100,
	EVENT_T1END = 	0x200,
	EVENT_EDCERR = 0x400
}usim_event_type_enum;

typedef enum{
	USIM_NO_ERROR = 0,

	// expected status
	USIM_WAITING_EVENT = 1,		// initial wait event status
	USIM_BLOCK_REC = 2,		// successfully received a complete block
	USIM_POWER_OFF = 3,		// successfully powered off
	USIM_ATR_REC = 4,			// successfully reveived all ATR
	USIM_S_BLOCK_REC = 5,	// successfully reveived S RESP
	USIM_WAITING_SWRST = 6,	// successfully reveived SWRST interrupt	

	// error status
	USIM_NO_INSERT = -1,        //fffffff
	USIM_VOLT_NOT_SUPPORT = -2, //ffffffe
	USIM_NO_ATR = -3,           //ffffffd
	USIM_TS_INVALID = -4,       //ffffffc
	USIM_ATR_ERR = -5,          //ffffffb
	USIM_INVALID_ATR = -6,      //ffffffa
	USIM_PTS_FAIL = -7,         //ffffff9
	USIM_RX_INVALID = -8,	// EDC error or parity error //ffffff8
	USIM_BWT_TIMEOUT = -9,      //ffffff7
	USIM_DATA_ABORT = -10,      //ffffff6
	USIM_DEACTIVATED = -11,     //ffffff5
	USIM_S_BLOCK_FAIL = -12,    //ffffff4
	USIM_INVALID_WRST = -13,    //ffffff3 
	USIM_GPT_TIMEOUT = -14      //ffffff2
}usim_status_enum;

typedef enum{
	USIM_CMD_READY,
	I_BLOCK_RX,
	I_BLOCK_TX,
	I_BLOCK_M0_RX,
	I_BLOCK_M0_TX,
	I_BLOCK_M1_RX,
	I_BLOCK_M1_TX,
	R_BLOCK_RX,
	R_BLOCK_TX,
	S_BlOCK_REQ_RX,
	S_BlOCK_REQ_TX,
	S_BlOCK_RESP_RX,
	S_BlOCK_RESP_TX
}usim_cmd_state_enum;

typedef enum{
 T1_NAD_INDEX		=		0,
 T1_PCB_INDEX		=		1,
 T1_LEN_INDEX		=		2,
 T1_INF_INDEX		=		3,
 T1_EDC_INDEX		=		4
}usim_t1_header_index_enum;

#if defined SIM_DRV_IC_USB
typedef enum{
	SIM_ICUSB_INIT,
	SIM_ICUSB_SETVOLT,
	SIM_ICUSB_ENABLESESSION,
	SIM_ICUSB_POWERON,
	SIM_ICUSB_CMD,
	SIM_ICUSB_POWEROFF,
	SIM_ICUSB_DISABLESESSION,
	SIM_ICUSB_DEINIT,
	SIM_ICUSB_ERRORHANDLING,

}usim_icusb_state_enum;
typedef enum
{
   SIM_ICUSB_ACK_OK = 0x00,
   SIM_ICUSB_ACK_PREFER_3V = 0x10,
   SIM_ICUSB_ACK_CMD_EN_SESSION_ERROR = 0xEA,
   SIM_ICUSB_ACK_SET_VOLTAGE_ERROR = 0xEB,
   SIM_ICUSB_ACK_CMD_TYPE_ERROR = 0xEC,
   SIM_ICUSB_ACK_NEED_RX_TO_ACK = 0xEE,
   SIM_ICUSB_ACK_CMD_ERROR = 0xFD,
   SIM_ICUSB_ACK_TIMEOUT = 0xFE,
   SIM_ICUSB_ACK_NO_CARD = 0xFF,


	// error status
   SIM_ICUSB_CCCI_CMD_EN_SESSION_ERROR = 0x1000,
   SIM_ICUSB_CCCI_SET_VOLTAGE_ERROR,
   SIM_ICUSB_CCCI_CMD_TYPE_ERROR,
   SIM_ICUSB_CCCI_NEED_RX_TO_ACK,
   SIM_ICUSB_CCCI_CMD_ERROR,
   SIM_ICUSB_CCCI_TIMEOUT,
   SIM_ICUSB_CCCI_NO_CARD,   
}usim_icusb_ackStatus;
#define SIM_ICUSB_CONTROL_MESSAGE_LEN 0x9
#define SIM_ICUSB_MESSAGE_HEADER_LEN 0x6
#define TB15_ICUSB_MASK 0xC0
#define SIM_ICUSB_CONTROL_MESSAGE_TYPE 0x80
#define SIM_ICUSB_DATA_MESSAGE_TYPE 0x80
#endif

typedef enum{
	PDN_DEV_SIM,
	PDN_DEV_SIM2
}usim_pdn_dev;
// definitions
#define	SELECT_PW_RETRY	3
#define 	SELECT_DIR_RETRY	2
#define 	ATR_RETRY  		3
#define	INVALID_RETRY	3
#define	RESYNC_RETRY	3
#define 	IFS_RETRY		2
#define 	USIM_IFSD_MAX	0xFE

#define FI_DEFAULT		372
#define DI_DEFAULT		1
#define INIT_WWT_T0		(9600+400)	// etu	(initial work waiting time) +400 to cover some slow card
#define TOUT_OFFSET		0x10		// apply a offset to all timeout settings (4*16 = 64 etu)
#define BGT_T1				22 		// etu	(block guard time)
#define NAD					0			// node address byte
#define SIM_DEFAULT_TOUT_VALUE      0x983
#define SIM_CMD_TOUT_VALUE          0x1400


// coding of PCB for I-block (0xxxxxxx)
#define PCB_I_BIT8		0x80		// I-block must be 0, others(R,S) are 1
#define PCB_I_SEQ			0x40		// sequence number
#define PCB_I_M			0x20		// chaining more data bit(M)
#define PCB_I_RFU			0x1F		// RFU should be zero

// coding of PCB for R-block (100xxxxx)
#define PCB_R_N1			0x90
#define PCB_R_N0			0x80
#define PCB_R_BIT7		0x40		// R: 0, S:1, use to distinguish R-block with S-block
#define PCB_R_SEQ			0x10		// sequence number
#define PCB_R_STATUS		0x0f		// 0: error free, 1:EDC or parity error, 2: other errors
#define PCB_R_STATUS_EDC_ERR 		0x1
#define PCB_R_STATUS_OTHER_ERR 	0x2
#define PCB_R_STATUS_OK	 0x0
#define PCB_R_DEFAULT	0xe0

// coding of PCB for S-block (11xxxxxx)
#define PCB_S_DEFAULT	0xc0
#define PCB_S_RESP		0x20		// 1: a response, 0: a request
#define PCB_S_ID			0x1f


#define LEN_MIN_T1			0
#define LEN_MAX_T1			254
#define USIM_IFSC_DEFAULT	32
#define USIM_IFSD_DEFAULT	32
#define USIM_CWT_DEFAULT	8203		// (11 + 1>>13) etu
#define USIM_BWT_DEFAULT	15360		// (1<<4)*960
#define USIM_POW_CLASS_MSK	0x3f		// TAi bit 1~6
#define USIM_PTS_PS1_MSK	0x10
#define USIM_PTS_PS0_T1		0x1		// select T1 protocol
#define USIM_NAD_DEFAULT	0x0

#define USIM_EVENT			0x1

#define ATR_TA1_372_5		0x11
#define ATR_TA1_372_4		0x01
#define ATR_TA1_64			0x94
#define ATR_TA1_32			0x95
#define ATR_TA1_16			0x96   //speed 16
#define ATR_TA1_8			0x97   //speed 8


#define USIM_RETRY			3
#define INDEX_COUNT			4		// the count of the wline and sline
#define MAX_BWI				9
#define MAX_CWI				16
#define SIM_TOTAL_FIFO_LEN	16		// excep 6208
#define HIST_FIRST_USIM				0x80	// the first of the historical character of USIM
#define HIST_SEC_USIM				0x31	// the second of the historical character of USIM
#define HIST_FOUR_USIM				0x73	// the fourth of the historical character of USIM
#define USIM_DMA_MAX_SIZE			260
#define USIM_GPT_TIMEOUT_PERIOD  500	// x 10ms

typedef enum{
	RESYNC_REQ = PCB_S_DEFAULT,
	IFS_REQ = (PCB_S_DEFAULT|1),
	ABORT_REQ = (PCB_S_DEFAULT|2),
	WTX_REQ = (PCB_S_DEFAULT|3),
	RESYNC_RESP = RESYNC_REQ|PCB_S_RESP,
	IFS_RESP = IFS_REQ|PCB_S_RESP,
	ABORT_RESP = ABORT_REQ|PCB_S_RESP,
	WTX_RESP = WTX_REQ|PCB_S_RESP
}usim_s_block_id_enum;

typedef enum{
	SIM_DRIVER_ACT			= 0x00000001,
	SIM_DRIVER_DEACT			= 0x00000002,
	SIM_PDNDIS					= 0x00000003,
	SIM_PDNEN					= 0x00000004,
	SIM_INT_SIM				= 0x00000005,
	SIM_INT_USIM				= 0x00000006,
	SIM_DRIVER_ACT_SIMD		= 0x00000007,
	SIM_DRIVER_DEACT_SIMD	= 0x00000008,
	SIM_CMD_TX_LOG			= 0x00010001,
	SIM_CMD_INS_LOG			= 0x00010002,
	SIM_CMD_TXDELAY			= 0x00010003,
	SIM_INIT_USIM				= 0x00020001,
	SIM_DEACTIVATE_1			= 0x00030001,
	SIM_DEACTIVATE_2			= 0x00030002,
	SIM_ACTION_RESET			= 0x000F0001,
	SIM_ACTION_POWOFF		= 0x000F0002,
	SIM_ACTION_COMMAND		= 0x000F0003,
	SIM_ACTION_EOC			= 0x000F0004
}sim_msgTag;


typedef enum{
	/*following is error*/
	SIM_PRINT_DUMP_ERROR_LINE,
	SIM_PRINT_RESET_NOATR_FAIL,
	SIM_PRINT_RESET_FAIL_WITH_TS_HSK_ENABLE,
	SIM_PRINT_RESET_FAIL_RESULT,
	SIM_PRINT_SIM_CMD_FAIL_STATUS,
	SIM_PRINT_CMD_FAIL_RESULT_STATUS,
	SIM_PRINT_RECEIVE_ERR_1,
	SIM_PRINT_RECEIVE_ERR_2,
	SIM_PRINT_TCK_CHECKSUM_ERR,
	SIM_PRINT_HISTORICAL_BYTE_ERR,
	SIM_PRINT_L1USIM_RESET_FAIL,

	/*following is information*/
	SIM_PRINT_INFO_BASE = 1000,
	SIM_PRINT_RESET_OK_POWER_SPEED,
	SIM_PRINT_NULL_TIME_OUT,
	SIM_PRINT_NULL_BYTE,
	SIM_PRINT_NON_NULL_BYTE,
	SIM_PRINT_9000_ON_SELECT,
	SIM_PRINT_6100_FROM_CARD,
	SIM_PRINT_CHECK_TCK,
	SIM_PRINT_TCK_NOT_PRESENT,
	SIM_PRINT_TCK_CHECKSUM_OK,
	SIM_PRINT_IR_CARD,
	SIM_PRINT_INDIRECT_CARD,
	SIM_PRINT_L1USIM_RST_OK,

	SIM_PRINT_L1SIM_CMD_TRC1 = 1101,
	SIM_PRINT_L1SIM_CMD_TRC2,
	SIM_PRINT_L1SIM_CMD_TRC3,
	SIM_PRINT_L1SIM_CMD_TRC4,
	SIM_PRINT_L1SIM_CMD_TRC5,
	SIM_PRINT_L1SIM_CMD_TRC6,	
	SIM_PRINT_L1SIM_CMD_TRC7,
	SIM_PRINT_L1SIM_CMD_TRC8,
	SIM_PRINT_L1SIM_CMD_TRC9,
	SIM_PRINT_L1SIM_CMD_TRC10 = 1110,
	SIM_PRINT_L1SIM_CMD_TRC11,	
	SIM_PRINT_L1SIM_CMD_TRC12,
	SIM_PRINT_L1SIM_CMD_TRC13,
	SIM_PRINT_L1SIM_CMD_TRC14,
	SIM_PRINT_L1SIM_CMD_TRC15,
	SIM_PRINT_L1SIM_CMD_TRC16,	
	SIM_PRINT_L1SIM_CMD_TRC17,
	SIM_PRINT_L1SIM_CMD_TRC18,
	SIM_PRINT_L1SIM_CMD_TRC19,
	SIM_PRINT_L1SIM_CMD_TRC20 = 1120,	
	SIM_PRINT_L1SIM_CMD_TRC21,	
	SIM_PRINT_L1SIM_CMD_TRC22,	
	SIM_PRINT_L1SIM_CMD_TRC23,
	SIM_PRINT_L1SIM_CMD_TRC24,
	SIM_PRINT_L1SIM_CMD_TRC25,
	SIM_PRINT_L1SIM_CMD_TRC26,
	SIM_PRINT_L1SIM_CMD_TRC27,
	SIM_PRINT_L1SIM_CMD_TRC28,
	SIM_PRINT_L1SIM_CMD_TRC29,
	SIM_PRINT_L1SIM_CMD_TRC30 = 1130,
	SIM_PRINT_L1SIM_CMD_TRC31,
	SIM_PRINT_L1SIM_CMD_TRC32,
	SIM_PRINT_L1SIM_CMD_TRC33,
	SIM_PRINT_L1SIM_CMD_TRC34,
	SIM_PRINT_L1SIM_CMD_TRC35,
	SIM_PRINT_L1SIM_CMD_TRC36,
	SIM_PRINT_L1SIM_CMD_TRC37,
	SIM_PRINT_L1SIM_CMD_TRC38,
	SIM_PRINT_L1SIM_CMD_TRC39,
	SIM_PRINT_L1SIM_CMD_TRC40 = 1140, 
	SIM_PRINT_L1SIM_CMD_TRC41,
	SIM_PRINT_L1SIM_CMD_TRC42,
	SIM_PRINT_L1SIM_CMD_TRC43,
	SIM_PRINT_L1SIM_CMD_TRC44,
	SIM_PRINT_L1SIM_CMD_TRC45, 
	SIM_PRINT_L1SIM_CMD_TRC46,
	SIM_PRINT_L1SIM_CMD_TRC47,
	SIM_PRINT_L1SIM_CMD_TRC48,
	SIM_PRINT_L1SIM_CMD_TRC49,
	SIM_PRINT_L1SIM_CMD_TRC50 = 1150,
	SIM_PRINT_L1SIM_CMD_TRC51,
	SIM_PRINT_L1SIM_CMD_TRC52,
	SIM_PRINT_L1SIM_CMD_TRC53,
	SIM_PRINT_L1SIM_CMD_TRC54,
	SIM_PRINT_L1SIM_CMD_TRC55,
	SIM_PRINT_L1SIM_CMD_TRC56,
	SIM_PRINT_L1SIM_CMD_TRC57,
	SIM_PRINT_L1SIM_CMD_TRC58,
	SIM_PRINT_L1SIM_CMD_TRC59,
	SIM_PRINT_L1SIM_CMD_TRC60 = 1160,
	SIM_PRINT_L1SIM_CMD_TRC61,
	SIM_PRINT_L1SIM_CMD_TRC62,
	SIM_PRINT_L1SIM_CMD_TRC63, 
	SIM_PRINT_L1SIM_CMD_TRC64,
	SIM_PRINT_L1SIM_CMD_TRC65, 
	SIM_PRINT_L1SIM_CMD_TRC66,
	SIM_PRINT_L1SIM_CMD_TRC67,
	SIM_PRINT_L1SIM_CMD_TRC68,
	SIM_PRINT_L1SIM_CMD_TRC69, //last
	SIM_PRINT_L1SIM_CMD_TRC70,
	SIM_PRINT_L1SIM_CMD_TRC71,
	SIM_PRINT_L1SIM_CMD_TRC72,
	SIM_PRINT_L1SIM_CMD_TRC73,
	SIM_PRINT_L1SIM_CMD_TRC74,
	SIM_PRINT_L1SIM_CMD_TRC75,
	SIM_PRINT_L1SIM_CMD_TRC76,
	SIM_PRINT_L1SIM_CMD_TRC77,
	SIM_PRINT_L1SIM_CMD_TRC78,
	SIM_PRINT_L1SIM_CMD_TRC79,
	SIM_PRINT_L1SIM_CMD_TRC80,	
	SIM_PRINT_L1SIM_CMD_TRC81,
	SIM_PRINT_L1SIM_CMD_TRC82,
	SIM_PRINT_L1SIM_CMD_TRC83,
	SIM_PRINT_L1SIM_CMD_TRC84,
	SIM_PRINT_L1SIM_CMD_TRC85,
	SIM_PRINT_L1SIM_CMD_TRC86,
	SIM_PRINT_L1SIM_CMD_TRC87,
	SIM_PRINT_L1SIM_CMD_TRC88,
	SIM_PRINT_L1SIM_CMD_TRC89,	
	SIM_PRINT_L1SIM_CMD_TRC90,	
	SIM_PRINT_L1SIM_CMD_TRC91,
	SIM_PRINT_L1SIM_CMD_TRC92,
	SIM_PRINT_L1SIM_CMD_TRC93,
	SIM_PRINT_L1SIM_CMD_TRC94,
	SIM_PRINT_L1SIM_CMD_TRC95,
	SIM_PRINT_L1SIM_CMD_TRC96,
	SIM_PRINT_L1SIM_CMD_TRC97,
	SIM_PRINT_L1SIM_CMD_TRC98,
	SIM_PRINT_L1SIM_CMD_TRC99,	
	SIM_PRINT_L1SIM_CMD_TRC100, 
	SIM_PRINT_L1SIM_CMD_TRC101,
	SIM_PRINT_L1SIM_CMD_TRC102,
	SIM_PRINT_L1SIM_CMD_TRC103,
	SIM_PRINT_L1SIM_CMD_TRC104,
	SIM_PRINT_L1SIM_CMD_TRC105,
	SIM_PRINT_L1SIM_CMD_TRC106,
	SIM_PRINT_L1SIM_CMD_TRC107,
	SIM_PRINT_L1SIM_CMD_TRC108,
	SIM_PRINT_L1SIM_CMD_TRC109, 
	SIM_PRINT_L1SIM_CMD_TRC110, 
	SIM_PRINT_L1SIM_CMD_TRC111,
	SIM_PRINT_L1SIM_CMD_TRC112,
	SIM_PRINT_L1SIM_CMD_TRC113,
	SIM_PRINT_L1SIM_CMD_TRC114,
	SIM_PRINT_L1SIM_CMD_TRC115,
	SIM_PRINT_L1SIM_CMD_TRC116,
	SIM_PRINT_L1SIM_CMD_TRC117,
	SIM_PRINT_L1SIM_CMD_TRC118,
	SIM_PRINT_L1SIM_CMD_TRC119, 	
	SIM_PRINT_L1SIM_CMD_TRC120, 			
	SIM_PRINT_L1SIM_CMD_TRC121,
	SIM_PRINT_L1SIM_CMD_TRC122,
	SIM_PRINT_L1SIM_CMD_TRC123,
	SIM_PRINT_L1SIM_CMD_TRC124,
	SIM_PRINT_L1SIM_CMD_TRC125,
	SIM_PRINT_L1SIM_CMD_TRC126,
	SIM_PRINT_L1SIM_CMD_TRC127,
	SIM_PRINT_L1SIM_CMD_TRC128,
	SIM_PRINT_L1SIM_CMD_TRC129,	
}sim_printEnum;



#endif /*__SIM_DRV_HW_DEF_MTK_H__*/
