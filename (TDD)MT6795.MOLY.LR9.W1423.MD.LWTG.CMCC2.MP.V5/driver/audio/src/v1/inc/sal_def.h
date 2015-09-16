#ifndef SAL_DEF_H
#define SAL_DEF_H

#include "common_def.h"

#define _SAL_DUALMIC_SUPPORT_    (!defined(MT6280))
#define _SAL_MIC34_SUPPORT_      (defined(MT6595) || defined(MT6752))
#define _SAL_ANC_SUPPORT_        (defined(MT6595) || defined(MT6752))  
#define _SAL_ENABLE_SW_SIDETONE_ (!defined(MT6280))

#define SAL_BIT0   0x0001
#define SAL_BIT1   0x0002
#define SAL_BIT2   0x0004
#define SAL_BIT3   0x0008
#define SAL_BIT4   0x0010
#define SAL_BIT5   0x0020
#define SAL_BIT6   0x0040
#define SAL_BIT7   0x0080
#define SAL_BIT8   0x0100
#define SAL_BIT9   0x0200
#define SAL_BIT10  0x0400
#define SAL_BIT11  0x0800
#define SAL_BIT12  0x1000
#define SAL_BIT13  0x2000
#define SAL_BIT14  0x4000
#define SAL_BIT15  0x8000

#define SAL_DEV_NORMAL	  		0
#define SAL_DEV_EARPHONE  		1
#define SAL_DEV_LOUDSPK			2
#define SAL_DEV_BT_EARPHONE_NB 	3
#define SAL_DEV_BT_EARPHONE_WB 	4
#define SAL_DEV_BT_CORDLESS 	5
#define SAL_DEV_MAX_NUM 		6

#define SAL_APP_TYPE_2GCall 0
#define SAL_APP_TYPE_3GCall 1
#define SAL_APP_TYPE_4GCall 2
#define SAL_APP_TYPE_PCM_Router 3

#define SAL_ENH_AEC		0
#define SAL_ENH_NR_UL	1
#define SAL_ENH_NR_DL	2
#define SAL_ENH_TDNC	3
#define SAL_ENH_DMNR	4


#define SAL_FLTCOEFLEN_SIDETONE 31
#define SAL_FLTCOEFLEN_BKF_NB 	45
#define SAL_FLTCOEFLEN_BKF_WB 	90
#define SAL_FLTCOEFLEN_SRC 		82
#define SAL_FLTCOEFLEN_AGC 		40
#define SAL_FLTCOEFLEN_DMNR_NB 	44
#define SAL_FLTCOEFLEN_DMNR_WB	76
#define SAL_PARAMETERLEN_COMMON 12
#define SAL_PARAMETERLEN_MODE_NB 	16
#define SAL_PARAMETERLEN_MODE_WB 	16
#define SAL_PARAMETERLEN_NOTCH 	15
#define SAL_PARAMETERLEN_INTERNAL 16

#define SPH_SFE_SRC_UL_DS            SAL_BIT1
#define SPH_SFE_SRC_DL_US            SAL_BIT2
#define SPH_SFE_SRC_UL4_DS           SAL_BIT4
#define SPH_SFE_SRC_UL3_DS           SAL_BIT5
#define SPH_SFE_SRC_UL2_DS           SAL_BIT6
#define SPH_SFE_SRC_UL_US            SAL_BIT7
#define SPH_SFE_SRC_DL_DS            SAL_BIT8
#define SPH_SFE_SRC_PCM_RT_8K2SD_US  SAL_BIT12
#define SPH_SFE_SRC_PCM_RT_8K2SD_DS  SAL_BIT13
#define SPH_SFE_SRC_PCM_RT_SE28K_US  SAL_BIT14
#define SPH_SFE_SRC_PCM_RT_SE28K_DS  SAL_BIT15


#define SAL_3G_VALUE_TX_CODEC_MODE 0
#define SAL_3G_VALUE_RX_CODEC_MODE 1
#define SAL_3G_VALUE_TX_TYPE 2
#define SAL_3G_VALUE_RX_TYPE 3

#define SAL_3G_ADDR_TXHB   0
#define SAL_3G_ADDR_RXHB   1


#define SAL_3G_TX_SPEECH_GOOD  2
#define SAL_3G_TX_SID_FIRST    1
#define SAL_3G_TX_SID_UPDATE   3
#define SAL_3G_TX_NO_DATA      0

#define SAL_3G_RX_SPEECH_GOOD  0
#define SAL_3G_RX_SPEECH_BAD   4
#define SAL_3G_RX_SID_FIRST    6
#define SAL_3G_RX_SID_UPDATE   8
#define SAL_3G_RX_SID_BAD      10
#define SAL_3G_RX_NO_DATA      14




#define SAL_DSPINT_PRIO_REC_EPL 1 //uplink
#define SAL_DSPINT_PRIO_REC_PCM 2 //uplink
#define SAL_DSPINT_PRIO_REC_VM  3 //downlink
#define SAL_DSPINT_PRIO_3G_DL	4
#define SAL_DSPINT_PRIO_3G_UL	5
#define SAL_DSPINT_PRIO_VOLTE_DL	6
#define SAL_DSPINT_PRIO_VOLTE_UL	7
#define SAL_DSPINT_PRIO_PNW_DL	8
#define SAL_DSPINT_PRIO_PNW_UL	9
#define SAL_DSPINT_PRIO_DACA_DL	10
#define SAL_DSPINT_PRIO_DACA_UL	11
#define SAL_DSPINT_PRIO_BGS_DL	12 //downlink, ping pong
#define SAL_DSPINT_PRIO_BGS_UL	13 
#define SAL_DSPINT_PRIO_AVBT	14
#define SAL_DSPINT_PRIO_WARN_MSG_UL	15
#define SAL_DSPINT_PRIO_WARN_MSG_DL	16
#define SAL_DSPINT_PRIO_4G_DL	17
#define SAL_DSPINT_PRIO_4G_UL	18
#define SAL_DSPINT_PRIO_MAX     19


#define SAL_DSPINT_ID_REC_EPL   (1 << SAL_DSPINT_PRIO_REC_EPL)
#define SAL_DSPINT_ID_REC_PCM   (1 << SAL_DSPINT_PRIO_REC_PCM)
#define SAL_DSPINT_ID_REC_VM    (1 << SAL_DSPINT_PRIO_REC_VM)
#define SAL_DSPINT_ID_3G_DL		(1 << SAL_DSPINT_PRIO_3G_DL)
#define SAL_DSPINT_ID_3G_UL		(1 << SAL_DSPINT_PRIO_3G_UL)
#define SAL_DSPINT_ID_VOLTE_DL	(1 << SAL_DSPINT_PRIO_VOLTE_DL)
#define SAL_DSPINT_ID_VOLTE_UL	(1 << SAL_DSPINT_PRIO_VOLTE_UL)
#define SAL_DSPINT_ID_PNW_DL	(1 << SAL_DSPINT_PRIO_PNW_DL)
#define SAL_DSPINT_ID_PNW_UL	(1 << SAL_DSPINT_PRIO_PNW_UL)
#define SAL_DSPINT_ID_DACA_DL	(1 << SAL_DSPINT_PRIO_DACA_DL)
#define SAL_DSPINT_ID_DACA_UL	(1 << SAL_DSPINT_PRIO_DACA_UL)
#define SAL_DSPINT_ID_BGS_DL	(1 << SAL_DSPINT_PRIO_BGS_DL)
#define SAL_DSPINT_ID_BGS_UL	(1 << SAL_DSPINT_PRIO_BGS_UL)
#define SAL_DSPINT_ID_AVBT		(1 << SAL_DSPINT_PRIO_AVBT)
#define SAL_DSPINT_ID_WARN_MSG_UL		(1 << SAL_DSPINT_PRIO_WARN_MSG_UL)
#define SAL_DSPINT_ID_WARN_MSG_DL		(1 << SAL_DSPINT_PRIO_WARN_MSG_DL)
#define SAL_DSPINT_ID_4G_DL		(1 << SAL_DSPINT_PRIO_4G_DL)
#define SAL_DSPINT_ID_4G_UL		(1 << SAL_DSPINT_PRIO_4G_UL)

typedef enum{
	SAL_PCM_NARROWBAND = 0,
	SAL_PCM_WIDEBAND,
	SAL_PCM_DYNAMIC
}Sal_PcmBand_Config_t;

typedef enum{
	SAL_PCMEX_OFF = 0,
	SAL_PCMEX_ON,
	SAL_PCMEX_RDY,
}Sal_PcmEx_State_t;



typedef enum{
	SAL_PCMEX_TYPE_PNW = 0,
	SAL_PCMEX_TYPE_DACA,
	SAL_PCMEX_TYPE_REC_NML,
	SAL_PCMEX_TYPE_REC_EPL, //no actual dsp control before MT6589
	SAL_PCMEX_TYPE_VOLTE
}Sal_PcmEx_Type_t;


typedef enum{
	SAL_PCMEX_SWITCH_OFF = 0,
	SAL_PCMEX_SWITCH_ON
}Sal_PcmEx_Switch_t;

typedef enum{
	SAL_PCMEX_PNW_BUF_UL1 = 0,//D2M
	SAL_PCMEX_PNW_BUF_UL2,//M2D
	SAL_PCMEX_PNW_BUF_UL3,
	SAL_PCMEX_PNW_BUF_UL4,
	SAL_PCMEX_PNW_BUF_DL1,//D2M
	SAL_PCMEX_PNW_BUF_DL2,//M2D
	SAL_PCMEX_DACA_BUF_UL,
	SAL_PCMEX_DACA_BUF_DL,
	SAL_PCMEX_BUF_SE,
	SAL_PCMEX_BUF_SE2,//mic2
	SAL_PCMEX_BUF_SD,
	SAL_PCMEX_VOLTE_BUF_UL,
	SAL_PCMEX_VOLTE_BUF_DL
	
}Sal_PcmEx_BufId_t;


typedef struct{

	Sal_PcmEx_Switch_t swi;

	Sal_PcmEx_Type_t type;
	
	bool idle;//must be assinged
	Sal_PcmBand_Config_t band;//taking effect only when idle is true
	uint16 delR;
	uint16 delW;
	uint16 delM;


	//for pcm n way
	bool afterEnh_ul1;
	bool D2M_ul1;
	bool M2D_ul1;
	bool afterEnh_ul2;
	bool D2M_ul2;
	bool M2D_ul2;
	bool afterEnh_ul3;
	bool D2M_ul3;
	bool M2D_ul3;
	bool afterEnh_ul4;
	bool D2M_ul4;
	bool M2D_ul4;
	bool DMNR_cal;//dsp pnw ul will copy pcm to M2D buffer

	bool afterEnh_dl; //position
	bool D2M_dl; //dl position is different from daca on bgs and keytone
	bool M2D_dl;

	
}Sal_PCMEx_Config_t;


typedef enum{
	SAL_VM_SWITCH_OFF = 0,
	SAL_VM_SWITCH_ON
}Sal_VM_Switch_t;


typedef struct{
	
	Sal_VM_Switch_t swi;
	bool idle;

	uint16 delR;
	uint16 delW;
	uint16 delM;
	uint16 codec;

}Sal_VM_Config_t;


typedef struct{

	uint16 enc_mode;
	uint16 dec_mode;

	uint16 enc_hdr;
	uint16 dec_hdr;

	volatile uint16 *enc_hb_addr;
	volatile uint16 *dec_hb_addr;

	volatile uint16 *dbgInfo_addr;
	volatile uint16 *enh_dbgInfo_addr;
		
}Sal_VM_Frame;

#define SAL_VM_DBGINFO_LEN 56
#define SAL_VM_ENH_DBGINFO_LEN 69
#define SAL_VM_DRV_DBGINFO_LEN 20

typedef struct{

	uint16 ul_pre_len;
	uint16 ul_pos_len;
	uint16 dl_pre_len;
	uint16 dl_pos_len;
	
	uint16 ul2_pos_len;
	uint16 ul3_pos_len;
	uint16 ul4_pos_len;

	volatile uint16 *ul_pre_buf;
	volatile uint16 *ul_pos_buf;
	volatile uint16 *dl_pre_buf;
	volatile uint16 *dl_pos_buf;

	volatile uint16 *ul2_pos_buf;
	
	volatile uint16 *ul3_pos_buf;
	volatile uint16 *ul4_pos_buf;

}Sal_EPL_Frame;


typedef enum{
	SAL_BT_MODE_LINEAR = 0,
	SAL_BT_MODE_SIGNEXT,
	SAL_BT_MODE_GAIN
}Sal_BT_Mode_t;

typedef enum{
	SAL_BT_LINEAR_GAIN_FIXED = 0,//fixed to 18db
	SAL_BT_LINEAR_ZPAD,//last 3 bits
	SAL_BT_LINEAR_GAIN_CONFIG_ZPAD
}Sal_BT_Linear_Ctrl_t;

typedef struct{

	bool feed_cfg;// false: clear bt config
	Sal_BT_Mode_t mode;

	//for linear mode
	Sal_BT_Linear_Ctrl_t linear_ctrl;
	bool linear_reverse;
	uint8 linear_ul_gain;

	//for gain mode
	uint8 gainmode_dl_gain;
	
}Sal_BT_Config;

typedef enum{
	SAL_MUTE_UL_POS_EN,
	SAL_MUTE_UL_PRE_EN,
	SAL_MUTE_UL_IN_EN,
	SAL_MUTE_DL_PRE_SD,
	SAL_MUTE_DL_PRE_EN,
	SAL_MUTE_DL_8K
}Sal_Mute_Point_t;

typedef enum{
	SAL_ENH_DYNAMIC_MUTE_UL,
	SAL_ENH_DYNAMIC_DMNR_MUX,
	SAL_ENH_DYNAMIC_VCE_MUX,
	SAL_ENH_DYNAMIC_BWE_MUX,
	SAL_ENH_DYNAMIC_UL_NR_MUX,
	SAL_ENH_DYNAMIC_DL_NR_MUX,
	SAL_ENH_DYNAMIC_DMNR_HF_MUX,
	SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX,
	SAL_ENH_DYNAMIC_DL_NR_INIT_CTRL_MUX,
	SAL_ENH_DYNAMIC_AEC_MUX,
	SAL_ENH_DYNAMIC_NUM //for salu using
}Sal_Enh_Dynamic_t;

typedef struct{

	bool main_switch;
	bool gain_switch;//false->fixed_gain
	bool hpiir_switch;
	bool vad_switch;
	bool cosim;
	bool init_req;
	
}Sal_AGC_Config_t;


typedef enum{
	SAL_VOLTE_INFO_JBM_OUT_SN,//for vm logging
	SAL_VOLTE_INFO_NUM //for salu using
}Sal_VOLTE_info_t;

typedef struct{
	
	uint16 cod_band; //0: NB, 1: WB
	uint16 dev_band; //0: NB, 1: WB
	uint16 delR;
	uint16 delW;
	uint16 delM_DL;
	uint16 delM_UL;	
	
}Sal_PCM_Router_t;

#define SAL_CTM_VALUE_TYPE_FACCH_REPORT 0
#define SAL_CTM_VALUE_TYPE_AMR_RX_RATE 1

#define SAL_UNKNOWN 0xeeee

#endif

