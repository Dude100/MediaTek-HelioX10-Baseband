/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    sim_MT6302.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for header files for MT6302 related control code
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SIM_MT6302_H__
#define __SIM_MT6302_H__

#include "MT6302_spi.h"

//efine	DRV_2_SIM_USING_LTC4558
#define	__DRV_2_SIM_USING_MT6302__
#define	SIM_MT6302_MAX_INTERFACES	2

#define	SIM_MT6302_REG_NUMBER	6
#define	SIM_MT6302_REG_RST	0
#define	SIM_MT6302_REG_CLK		1
#define	SIM_MT6302_REG_DAT	2
#define	SIM_MT6302_REG_VCC	3
#define	SIM_MT6302_CONFMSK	0x33B
#define 	SIM_MT6302_SERVING_INTERFACE_NONE		0xff

#if defined(DRV_SIM_DBG_LOW_COST_ULC)
#define	SIM_MT6302_MSG_NUM			256
#elif defined(DRV_SIM_DBG_LOW_COST_COMMON)
#define	SIM_MT6302_MSG_NUM			512
#else
#define	SIM_MT6302_MSG_NUM			1024
#endif

#ifdef DRV_2_SIM_USING_LTC4558
#define SIM_MT6302_GPIO_LTC4558_CLKRUNA	4
#define SIM_MT6302_GPIO_LTC4558_CLKRUNB	7
#define SIM_MT6302_GPIO_LTC4558_ENABLEA	8
#define SIM_MT6302_GPIO_LTC4558_ENABLEB	9
#define SIM_MT6302_GPIO_LTC4558_CSEL			11
#define SIM_MT6302_GPIO_LTC4558_VSELA		12
#define SIM_MT6302_GPIO_LTC4558_VSELB		13
#endif

#ifndef __SIM_DRV_MULTI_DRV_ARCH__

#define MT6302_RACE_PROTECT(a) \
{ \
	if(0 < MT6302_raceConditionProtect[a]) \
		ASSERT(0); \
	MT6302_raceConditionProtect[a] ++; \
}

#define MT6302_RACE_RELEASE(a) \
{MT6302_raceConditionProtect[a] -- ;}

#else

#define MT6302_RACE_PROTECT(a) \
{ \
	if(0 < switch_CB->MT6302_raceConditionProtect[a]) \
		ASSERT(0); \
	switch_CB->MT6302_raceConditionProtect[a] ++; \
}

#define MT6302_RACE_RELEASE(a) \
{switch_CB->MT6302_raceConditionProtect[a] -- ;}

#endif


typedef enum{
	SIM_MT6302_SELECT_LTC4558	= 0x00030001,
	SIM_MT6302_RETREIVE_BAUD	= 0x00030002,
	SIM_MT6302_CLOCK_CTRL		= 0x00030003,
	SIM_MT6302_VCC_CTRL			= 0x00030004,
	SIM_MT6302_VCC_LVL_CTRL		= 0x00030005,
	SIM_MT6302_ACT_SIM_CTRL		= 0x00030006,
	SIM_MT6302_DEACT_SIM_CTRL	= 0x00030007,
	SIM_MT6302_RST_CTRL			= 0x00030008,
	SIM_MT6302_DAT_CTRL			= 0x00030009,

	SIM_MT6302_BLOCK_DAT			= 0x00040001,
	SIM_MT6302_BLOCK_RST			= 0x00040002,
	SIM_MT6302_PASS_DAT			= 0x00040003,
	SIM_MT6302_PASS_RST			= 0x00040004,
	SIM_MT6302_PASS_CLK			= 0x00040005,
	SIM_MT6302_BLOCK_CLK			= 0x00040006,

	SIM_MT6302_D2D					= 0x00050001,
	SIM_MT6302_D2S					= 0x00050002,
	SIM_MT6302_R2D					= 0x00050003,
	SIM_MT6302_R2R					= 0x00050004,
	SIM_MT6302_R2S					= 0x00050005,
	SIM_MT6302_S2D					= 0x00050006,
	SIM_MT6302_S2R					= 0x00050007,
	SIM_MT6302_S2S					= 0x00050008,
	SIM_MT6302_D2R					= 0x00050009, /*this is only valid in MT6302*/

	SIM_MT6302_CHANGE_LISR		= 0x00060001,
	SIM_MT6302_CHANGE_CARD_STATE	= 0x00060002,
	SIM_MT6302_CHANGE_CURRENT_LISR	= 0x00060003,
	SIM_MT6302_CHANGE_CARD_TYPE	= 0x00060004,

	SIM_MT6302_DRIVER_ACT		= 0x00070001,
	SIM_MT6302_DRIVER_DEACT		= 0x00070002,
	SIM_MT6302_DRIVER_STOPCLK	= 0x00070003,
	SIM_MT6302_DRIVER_STARTCLK	= 0x00070004,
	SIM_MT6302_DRIVER_PDNEN		= 0x00070005,
	SIM_MT6302_DRIVER_PDNDIS	= 0x00070006,

	SIM_MT6302_ACTION_RESET		= 0x00080001,
	SIM_MT6302_ACTION_COMMAND	= 0x00080002,
	SIM_MT6302_ACTION_POWOFF	= 0x00080003,
	SIM_MT6302_ACTION_EOC		= 0x00080004,

	SIM_MT6302_TEST_1				= 0x00090001,
	SIM_MT6302_TEST_2				= 0x00090002,
	SIM_MT6302_TEST_3				= 0x00090003,
	SIM_MT6302_TEST_4				= 0x00090004,
	SIM_MT6302_TEST_5				= 0x00090005,
	SIM_MT6302_TEST_6				= 0x00090006,
	SIM_MT6302_TEST_7				= 0x00090007,
	SIM_MT6302_TEST_0				= 0x00090008,
	SIM_MT6302_TEST2_1			= 0x00090021,
	SIM_MT6302_TEST2_2			= 0x00090022,
	SIM_MT6302_TEST2_3			= 0x00090023,
	SIM_MT6302_TEST2_4			= 0x00090024,
	SIM_MT6302_TEST2_5			= 0x00090025,
	SIM_MT6302_TEST2_6			= 0x00090026,
	SIM_MT6302_TEST2_7			= 0x00090027,
	SIM_MT6302_TEST2_0			= 0x00090028,

	SIM_MT6302_CLKSTOP_TIMEOUT	= 0x000a0001,
	SIM_MT6302_CLKSTOP_START	= 0x000a0002,
	SIM_MT6302_CLKSTOP_ABORT	= 0x000a0003,
	SIM_MT6302_CLKSTOP_DEQUE	= 0x000a0004,

	SIM_MT6302_CLKSTART_START	= 0x000b0001,
	SIM_MT6302_CLKSTART_END		= 0x000b0002,
	SIM_MT6302_CLKSTART_HISR	= 0x000b0003,
	SIM_MT6302_CLKSTART_NEW_TRUE	= 0x000b0004,
	SIM_MT6302_CLKSTART_NEW_FALSE	= 0x000b0005,

	SIM_MT6302_SPI_WRITE			= 0x000c0001
}sim_MT6302_msgTag;

#if defined(__DRV_2_SIM_USING_MT6302__)

#define	MT6302_CLK_CFG_BLOCKED(simInterface)	((sim_MT6302_card[simInterface].pins.CLK & (0x5<<hw_cb->MT6302PortNo)) != (0x1<<hw_cb->MT6302PortNo))

/*MT6302 's pin state is more complicated, if I don't describe it precisely, I may encounter struggle in the future*/
typedef enum{
	sim_MT6302_VCC18VDisable = 0,
	sim_MT6302_VCC3VDisable = 1, 
	sim_MT6302_VCC18V = 4, // I plan to use ((reg_value >> simInterface) & 0x5) to assign the pin state value, thus the enum should be the same as reg value
	sim_MT6302_VCC3V = 5
} sim_MT6302_stateVCC;
	
typedef enum{
	sim_MT6302_DATBlockedHigh = 0,
	sim_MT6302_DATPass_High = 1,	//Data is now pass and controlled by the side that driving, but DATA_L is 0, that is, when we block it will become high
	sim_MT6302_DATBlockedLow = 5,
	sim_MT6302_DATBlockedHigh_Low = 4,	//Data is now block high but DATA_L is 1, that is, when we set DATAEN, it will become block low

	/*in following state, pin is stay in low lv because no ldo supply*/
	sim_MT6302_NoLDO_DATBlockedHigh = 0x10,
	sim_MT6302_NoLDO_DATPass_High = 0x11,
	sim_MT6302_NoLDO_DATBlockedLow = 0x15,
	sim_MT6302_NoLDO_DATBlockedHigh_Low = 0x14
	
} sim_MT6302_stateDAT;

typedef enum{
	sim_MT6302_CLKBlockedLow = 0,
	sim_MT6302_CLKPass = 1, 
	sim_MT6302_CLKBlockedHigh = 5,
	sim_MT6302_CLKInvalidState = 4,

	/*in following state, pin is stay in low lv because no ldo supply*/
	sim_MT6302_NoLDO_CLKBlockedLow = 0x10,
	sim_MT6302_NoLDO_CLKPass = 0x11, 
	sim_MT6302_NoLDO_CLKBlockedHigh = 0x15,
	sim_MT6302_NoLDO_CLKInvalidState = 0x14
} sim_MT6302_stateCLK;

typedef enum{
	sim_MT6302_RSTPass_Low = 0, //RSTVAL is low, that is, when we block RST, it will becomes block low
	sim_MT6302_RSTBlockedLow = 1,
	sim_MT6302_RSTBlockedHigh = 5,
	sim_MT6302_RSTPass_High = 4,//RSTVAL is high, that is, when we block RST, it will becomes block high

	/*in following state, pin is stay in low lv because no ldo supply*/
	sim_MT6302_NoLDO_RSTPass_Low = 0x10, 
	sim_MT6302_NoLDO_RSTBlockedLow = 0x11,
	sim_MT6302_NoLDO_RSTBlockedHigh = 0x15,
	sim_MT6302_NoLDO_RSTPass_High = 0x14
} sim_MT6302_stateRST;

#elif defined (DRV_2_SIM_USING_LTC4558)

typedef enum{
	sim_MT6302_VCCDisable = 0,
	sim_MT6302_VCC18V = 1,
	sim_MT6302_VCC3V = 2,
	sim_MT6302_VCCMaxValue
} sim_MT6302_stateVCC;
	
typedef enum{
	sim_MT6302_DATBlockedHigh = 0,
	sim_MT6302_DATPass = 1,
	sim_MT6302_DATBlockedLow = 2,
	sim_MT6302_DATMaxValue
} sim_MT6302_stateDAT;

typedef enum{
	sim_MT6302_CLKBlockedLow = 0,
	sim_MT6302_CLKPass = 1,
	sim_MT6302_CLKBlockedHigh = 2,
	sim_MT6302_CLKMaxValue
} sim_MT6302_stateCLK;

typedef enum{
	sim_MT6302_RSTBlockedLow = 0,
	sim_MT6302_RSTPass = 1,
	sim_MT6302_RSTBlockedHigh = 2,
	sim_MT6302_RSTMaxValue
} sim_MT6302_stateRST;

#endif

typedef enum{
	sim_MT6302_statusNoError = 0
} sim_MT6302_status;

typedef enum{
	sim_MT6302_eventReset = 0,
	sim_MT6302_eventCommand,
	sim_MT6302_eventPowerOff
} sim_MT6302_changeEvent;

typedef enum{
	sim_MT6302_stateDeactiavate = 0,
	sim_MT6302_stateClkRunning = 1,
	sim_MT6302_stateClkStopped = 2
} sim_MT6302_cardState;

typedef enum{
	sim_MT6302_cardTypeAL = 0,
	sim_MT6302_cardTypeIR = 1,
	sim_MT6302_cardTypeMaxValue
} sim_MT6302_cardType;

typedef enum{
	sim_MT6302_LISRnotRegistered = 0,
	sim_MT6302_LISRUsim = 1,
	sim_MT6302_LISRSim
} sim_MT6302_LISRState;

enum{
	sim_MT6302_protectionChange = 0,
	sim_MT6302_protectionSpi,
	sim_MT6302_protectionCmd,
	sim_MT6302_protectionRst,
	sim_MT6302_protectionPwf,
	sim_MT6302_protectionPdn,
	sim_MT6302_protectionState,
	sim_MT6302_protectionStopper,
	SIM_MT6302_MAX_PROTECTION_NUM
};



typedef struct{
	sim_MT6302_msgTag		tag;
	kal_uint32					event;
	kal_uint32					data1;
	kal_uint32					data2;
}sim_MT6302_msg;

typedef struct{
	sim_MT6302_stateCLK	CLK;
	sim_MT6302_stateDAT	DAT;
	sim_MT6302_stateRST	RST;
	sim_MT6302_stateVCC	VCC;
}sim_MT6302_pinStatus;

typedef struct{
	sim_MT6302_pinStatus	pins;
	sim_MT6302_cardState	state;
	sim_MT6302_cardType	type;
	sim_MT6302_LISRState	lisrState;
	kal_uint16					baud;
	kal_uint16					config;
	kal_uint32				sim_MT6302_gptHandle;
	kal_bool				sim_MT6302_clkStopQueued;
} sim_MT6302_cardInfo;

typedef struct{
	kal_uint32			MT6302ChipNo; //for which MT6302 chip does this control block stand
	sim_MT6302_SPIWriter	sim_MT6320_writer;
	kal_uint32			sim_MT6302_servingInterface;// the latest interface that controller is serving
	kal_semid			sim_MT6302_arb;
	kal_bool				sim_MT6302_taskAccessing;
	kal_bool				sim_MT6302_needCLKStartTimeout;
	kal_uint8				sim_MT6302_regValue[SIM_MT6302_REG_NUMBER];
	sim_MT6302_LISRState	sim_MT6302_registeredLISR;
	kal_bool				sim_MT6302_needManualControl; /*this flag will only be set true in MT6302*/
	kal_uint8				MT6302_raceConditionProtect[SIM_MT6302_MAX_PROTECTION_NUM];
	kal_bool				sim_workingTaskWaiting; //this is used to know whether serving task is waiting for event
	kal_bool				sim_MT6302_initialized;
#ifdef __SIM_DRV_MULTI_DRV_ARCH__
	sim_HW_cb 			*usim_waitHisrCb_MT6302; //record the hw_cb pointer to whom is using this switch's hisr
	sim_HW_cb 			*sim_waitHisrCb_MT6302; //record the hw_cb pointer to whom is using this switch's hisr
	kal_uint32			nullByteGPTServingInterface;
	/*following is for LCD SPI*/
	kal_uint32	MT6302_SPI_LCDSerialData;
	kal_uint8		MT6302_LCD_pdnHandle; /*lcd_get_power_handle will return value less than 32, set this as RW 0xff*/
#endif
} sim_MT6302_switchInfo;


#ifndef __SIM_DRV_MULTI_DRV_ARCH__
typedef sim_MT6302_status (*sim_MT6302_eventHandler)(kal_uint32, sim_MT6302_changeEvent);
#else
typedef sim_MT6302_status (*sim_MT6302_eventHandler)(sim_HW_cb *, sim_MT6302_changeEvent);
sim_MT6302_switchInfo *sim_MT6302_get_MT6302switchCB(sim_HW_cb *hw_cb);
sim_MT6302_cardInfo *sim_MT6302_get_MT6302CardCB(sim_HW_cb *hw_cb);
#endif

#endif //__SIM_MT6302_H__
