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
 *    dcl_sim.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines structures and functions for SIM DCL interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef DCL_DEFINITION_STRUCT

#ifndef __DCL_SIM_H_STRUCT__
#define __DCL_SIM_H_STRUCT__

/*RHR*/
//#include "kal_non_specific_general_types.h"
#include "dcl.h"
/*RHR*/

#define	DCL_SIM_MAX_INTERFACE	5

/*********************************************************************************************************
*followings we defines the structure used by DCL user, this is prevent DCL user from include invividual moudles' header file.
**********************************************************************************************************/
typedef DCL_UINT16 DCL_SIM_STATUS_WORD;

typedef enum
{
	DCL_ME_UNKNOW =0,
	DCL_ME_18V_30V,
	DCL_ME_30V_ONLY,
	DCL_ME_18V_ONLY
} DCL_SIM_ENV;

typedef enum{
	DCL_USIM_NO_ERROR = 0,

	/*expected status*/
	DCL_USIM_WAITING_EVENT = 1,	/* initial wait event status */
	DCL_USIM_BLOCK_REC = 2,		/* successfully received a complete block */
	DCL_USIM_POWER_OFF = 3,		/* successfully powered off */
	DCL_USIM_ATR_REC = 4,			/* successfully reveived all ATR */
	DCL_USIM_S_BLOCK_REC = 5,		/* successfully reveived S RESP */

	/* error status */
	DCL_USIM_NO_INSERT = -1,
	DCL_USIM_VOLT_NOT_SUPPORT = -2,
	DCL_USIM_NO_ATR = -3,
	DCL_USIM_TS_INVALID = -4,
	DCL_USIM_ATR_ERR = -5,
	DCL_USIM_INVALID_ATR = -6,
	DCL_USIM_PTS_FAIL = -7,
	DCL_USIM_RX_INVALID = -8,	/* EDC error or parity error */
	DCL_USIM_BWT_TIMEOUT = -9,
	DCL_USIM_DATA_ABORT = -10,
	DCL_USIM_DEACTIVATED = -11,
	DCL_USIM_S_BLOCK_FAIL = -12,
	DCL_USIM_INVALID_WRST = -13,
	DCL_USIM_GPT_TIMEOUT = -14
}DCL_SIM_STATUS;

/*All possible volatege support values. This enum to duplicate the same definition as internal SIM driver definition, so that protocol does not need to include driver internal header files*/
typedef enum{
	DCL_UNKNOWN_POWER_CLASS = 0,
	DCL_CLASS_A_50V = 1,							/*this card support 5V only, from ATR*/
	DCL_CLASS_B_30V = 2,							/*this card support 3V only, from ATR*/
	DCL_CLASS_AB 	= 3,								/*this card support 5V and 3V, from ATR*/
	DCL_CLASS_C_18V = 4,							/*this card support 1.8V only, from ATR*/
	DCL_ClASS_BC		= 6,							/*this card support 3V and 1.8V, from ATR*/
	DCL_CLASS_ABC	= 7									/*this card support 5V, 3V, and 1.8V, from ATR*/
}DCL_SIM_POWER;

typedef DCL_UINT32 DCL_SIM_HW_CB;

/*The application protocol support information. This enum to duplicate the same definition as internal SIM driver definition, so that protocol does not need to include driver internal header files*/
typedef enum
{
	DCL_SIM_PROTOCOL,			/*support SIM protocol, or to be more precisely, this should be a ICC card*/
	DCL_USIM_PROTOCOL			/*support USIM protocol, or to be more precisely, this should be a UICC card*/
}DCL_SIM_APP_PROTOCOL;



/*defines the possible choice of physical protocol. This enum to duplicate the same definition as internal SIM driver definition, so that protocol does not need to include driver internal header files*/
typedef enum
{
	DCL_T0_PROTOCOL,			/*prefer to use the T0 protocol*/
	DCL_T1_PROTOCOL,			/*prefer to use the T1 protocol*/
	DCL_UNKNOWN_PROTOCOL	/*no preferred physical protocol*/
}DCL_SIM_PHY_PROTOCOL;

/*defines the all of the clock stop related information. This enum to duplicate the same definition as internal SIM driver definition, so that protocol does not need to include driver internal header files*/
typedef enum{
	DCL_CLOCK_STOP_NOT_SUPPORT 	= 0x0,		/*not support clock stop*/
	DCL_CLOCK_STOP_LOW 			= 0x40,				/*support clock stop in low level*/
	DCL_CLOCK_STOP_HIGH 			= 0x80,			/*support clock stop in high level*/
	DCL_CLOCK_STOP_ANY				= 0xc0,			/*support clock stop in any voltage level*/
	DCL_CLOCK_STOP_MSK				= 0xc0,			/*define the clock stop mask, used to parse the information received from cards*/
	DCL_CLOCK_STOP_UNKONW			= 0x0f			/*the default value*/
}DCL_SIM_CLK_STOP;

/*defines the possible card speed values. This enum is to duplicate the same definition as internal SIM driver definition, so that protocol does not need to include driver internal header files*/
typedef enum{
	DCL_SPEED_372,		/*for speed372*/
	DCL_SPEED_64,			/*for speed64*/
	DCL_SPEED_32,			/*for speed32*/
	DCL_SPEED_16			/*for speed16*/
}DCL_SIM_CARD_SPEED;

/*the structure to define the values exchanged when doing get card information*/
typedef struct{
	DCL_SIM_POWER power; /*the voltage we choose*/
	DCL_SIM_CARD_SPEED speed; /*the speed we choose*/
	DCL_SIM_CLK_STOP clock_stop; /*clock stop information in ATR*/
	DCL_SIM_APP_PROTOCOL app_proto; /*whether it is a ICC card or UICC card*/
	DCL_SIM_PHY_PROTOCOL phy_proto; /*the physical protocol we used*/
	kal_bool T0_support;	/* if T0 is supported*/
	kal_bool T1_support;	/* if T1 is supported*/
	kal_uint8 hist_index; /* index to the historical char of ATR*/
	kal_uint8 *ATR; /*the pointer to store the ATR received*/
       kal_bool TAiExist; /*if the first TA for T=15 is existed*/
    kal_uint8 ATR_length;			/* length to the ATR_data*/
    kal_bool isSW6263; /* query if status word 0x62xx 0x63xx happen*/
}DCL_SIM_INFO;

/*******************************************************************************
 * driver function tables exposed to DCL
 *******************************************************************************/
/*here are type definition for functions*/
/*dcl add new api : 2. define function type*/

/*the prototype definition for RST function pointer*/
typedef DCL_SIM_STATUS (* DCL_SIM_RST)(DCL_SIM_POWER ExpectVolt, DCL_SIM_POWER *ResultVolt, kal_bool warm, DCL_SIM_HW_CB handle);
/*the prototype definition for CMD function pointer*/
typedef DCL_SIM_STATUS_WORD (* DCL_SIM_CMD)(kal_uint8  *txData,kal_uint32  *txSize,kal_uint8  *rxData, kal_uint32  *rxSize, DCL_SIM_HW_CB handle);
/*the prototype definition for power off function pointer*/
typedef void (* DCL_SIM_PWOFF)(DCL_SIM_HW_CB handle);
/*the prototype definition for get card info function pointer*/
typedef void (* DCL_SIM_GET_CARD_INFO)(DCL_SIM_INFO *info, DCL_SIM_HW_CB handle);
/*the prototype definition for set maximum speed function pointer*/
typedef void (* DCL_SIM_SET_MAX_SPEED)(DCL_SIM_CARD_SPEED speed, DCL_SIM_HW_CB handle);
/*the prototype definition for set prefer physical protocol function pointer*/
typedef void (* DCL_SIM_SET_PREFER_PROTOCOL)(DCL_SIM_PHY_PROTOCOL T, DCL_SIM_HW_CB handle);
/*the prototype definition for set clock stop mode function pointer*/
typedef kal_bool (* DCL_SIM_SET_CLK_STOP_MODE)(DCL_SIM_CLK_STOP mode, DCL_SIM_HW_CB handle);
/*the prototype definition for TOUT test function pointer*/
typedef void (* DCL_SIM_TOUT_TEST)(kal_uint32 toutValue, DCL_SIM_HW_CB handle);
/*the prototype definition for assign logical number function pointer*/
typedef kal_uint32 (* DCL_SIM_ASSIGN_LOGICAL)(kal_uint32 logicalNumber);
/*the prototype definition for get card speed function pointer*/
typedef DCL_SIM_CARD_SPEED (*DCL_SIM_GAT_CARD_SPEED)(DCL_SIM_HW_CB handle);
/*the prototype definition for query 9000 function pointer*/
typedef DCL_BOOL (*DCL_SIM_QUERY_GET_9000_WHEN_SELECT)(DCL_SIM_HW_CB handle);
/* For sim hot plug callback function */
/*the prototype definition for SIM hot plug out call back function*/
typedef void (*DCL_SIM_PLUG_OUT_CALLBACK)(kal_uint32 simIf);
/*the prototype definition for SIM hot plug in call back function*/
typedef void (*DCL_SIM_PLUG_IN_CALLBACK)(kal_uint32 simIf);

/*dcl add new api : 3. add to funtion table type*/

/*the declaration of SIM driver table, expeorted from SIM driver to DCL SIM interface. This table implies we accept any SIM driver function tables with the same format.*/
typedef struct
{
	DCL_SIM_RST rst; /*The RST function to detect card's existence*/
	DCL_SIM_CMD cmd; /*The CMD function to send the APDU command to the card*/
	DCL_SIM_PWOFF pwOff; /*The power off function to deactivate the card*/
	DCL_SIM_GET_CARD_INFO getCardInfo; /*To report the card information, known by SIM driver, to the protocol layer*/
	DCL_SIM_SET_MAX_SPEED setSpeed; /*To set the maximum allowed speed to driver*/
	DCL_SIM_SET_PREFER_PROTOCOL setPreferT; /*To set the preferred physical layer protocol to driver*/
	DCL_SIM_SET_CLK_STOP_MODE setClockStopMode; /*To set the CLK stop information, known by protocol, to driver*/
	DCL_SIM_TOUT_TEST toutTest; /*To ask the driver to start TOUT test*/
	DCL_SIM_ASSIGN_LOGICAL assignLogical; /*To Assign the logical number to specific card*/
	DCL_SIM_GAT_CARD_SPEED getCardSpeed; /*to get the card speed information*/
	DCL_SIM_QUERY_GET_9000_WHEN_SELECT query9000WhenSelect; /*To query whether a status word 0x9000 happened after SELECT command*/
}DCL_SIMDriver_t;

/* defines the possible application value*/
typedef enum
{
	SIM_CONFIG_AP_TYPE_PHONE1,		/*the card will be used for phone application SIM card 1*/
	SIM_CONFIG_AP_TYPE_PHONE2,		/*the card will be used for phone application SIM card 2*/
	SIM_CONFIG_AP_TYPE_CMMB_SMD,	/*the card will be used for CMMB SMD card*/
	SIM_CONFIG_AP_TYPE_PHONE3,		/*the card will be used for phone application SIM card 3*/
	SIM_CONFIG_AP_TYPE_PHONE4			/*the card will be used for phone application SIM card 4*/
} DCL_SIM_CONFIG_AP_TYPE;

/* defines the SIM configure structure */
typedef struct
{
	DCL_SIM_CONFIG_AP_TYPE	apType; /* define the application type protocol want to use*/
    DCL_SIM_PLUG_IN_CALLBACK hotPlugInCb; /* specify the hot plug in callback function pointer*/
	DCL_SIM_PLUG_OUT_CALLBACK hotPlugOutCb; /* specify the hot plug out callback function pointer*/
} SIM_CONFIG_T;

#define SIM_CONFIGS    \
   SIM_CONFIG_T   rSimConfig;

/*******************************************************************************
 * DCL_CTRL_CMD for SIM
 *******************************************************************************/
 /*dcl add new api : 4. add to DCL_CTRL_CMD enum*/

#ifdef __BUILD_DOM__
/*The SIM Command values in DCL_CTRL_CMD_T Enum of dcl.h*/
typedef enum
{
	 SIM_CTRL_CMD_RST, 			 		 							/*try to reset the card and tell its existence*/
	 SIM_CTRL_CMD_CMD, 			 		 							/*send APDU command to ICC/UICC*/
   SIM_CTRL_CMD_PWOFF,   		 								/*to power off the card*/
   SIM_CTRL_CMD_GET_CARD_INFO,			 				/*to get the card information stored in driver layer*/
   SIM_CTRL_CMD_SET_SPEED, 		 							/*set the maximum allowed speed*/
   SIM_CTRL_CMD_SET_PREFER_PROTOCOL,				/*to set the preferred physical protocl*/
   SIM_CTRL_CMD_SET_CLK_STOP_MODE,					/*to set the clock stop related setting*/
   SIM_CTRL_CMD_TOUT_TEST,			 						/*to start TOUT test, used by MEUT SIM test task*/
   SIM_CTRL_CMD_GET_SPEED,			 						/*to get the card speed information*/
   SIM_CTRL_CMD_QUERY_9000_ON_SELECT,				/*to querry whether 0x9000 after SELECT command happens*/
   SIM_CTRL_CMD_SET_SLT_RLT,				/*to set SLT result*/
}DCL_CTRL_CMD_T;
#else
#define SIM_CMDS    \
   SIM_CTRL_CMD_BASE, \
   SIM_CTRL_CMD_RST = 0, \
   SIM_CTRL_CMD_CMD, \
   SIM_CTRL_CMD_PWOFF, \
   SIM_CTRL_CMD_GET_CARD_INFO, \
   SIM_CTRL_CMD_SET_SPEED,  \
   SIM_CTRL_CMD_SET_PREFER_PROTOCOL, \
   SIM_CTRL_CMD_SET_CLK_STOP_MODE, \
   SIM_CTRL_CMD_TOUT_TEST, \
   SIM_CTRL_CMD_GET_SPEED, \
   SIM_CTRL_CMD_QUERY_9000_ON_SELECT, \
   SIM_CTRL_CMD_SET_SLT_RLT, \
   SIM_CTRL_CMD_MAX_VALUE, \
   SIM_CTRL_CMD_DUMMY_END = SIM_CTRL_CMD_BASE + SIM_CTRL_CMD_MAX_VALUE,
#endif /*__BUILD_DOM__*/


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
 
/* FOR SIM_CTRL_CMD_RST control command. */
typedef struct
{
	DCL_SIM_POWER ExpectVolt; /*the expected voltage from caller*/
	DCL_SIM_POWER *ResultVolt; /*the pointer to report the eventual reset voltage from driver*/
	kal_bool warm; /*to indicate whether this is cold reset or warm reset*/
	DCL_SIM_STATUS rstResult; /*the result*/
} SIM_CTRL_RST_T;

/* FOR SIM_CTRL_CMD_CMD control command. */
typedef struct
{
	kal_uint8  *txData;				/*the pointer to the tx data buffer*/
	kal_uint32  *txSize;			/*the pointer to the tx buffer size*/
	kal_uint8  *rxData;				/*the pointer to the tx data buffer*/
	kal_uint32  *rxSize;			/*the pointer to the rx buffer size, driver will then feedback actual receive size here*/
	kal_uint16 *statusWord;		/*the pointer to contains the status word from card*/
} SIM_CTRL_CMD_T;

/*dcl add new api : 4. new ctrl data type*/

/* FOR SIM_CTRL_CMD_GET_CARD_INFO control command. */
typedef struct
{
	DCL_SIM_INFO *info;				/*the pointer to DCL_SIM_INFO structure, SIM driver will filled the values of the structure*/
} SIM_CTRL_GET_CARD_INFO_T;

/* FOR SIM_CTRL_CMD_SET_SPEED control command. */
typedef struct
{
	DCL_SIM_CARD_SPEED speed;	/*the DCL_SIM_CARD_SPEED structure, the structure is to tell the driver the maximum allowed speed value*/
} SIM_CTRL_SET_MAX_SPEED_T;

/* FOR SIM_CTRL_CMD_SET_PREFER_PROTOCOL control command. */
typedef struct
{
	DCL_SIM_PHY_PROTOCOL T;		/*the DCL_SIM_PHY_PROTOCOL structure, the structure is to tell the driver the preferred physical protocol*/
} SIM_CTRL_SET_PREFER_PROTOCOL_T;

/* FOR SIM_CTRL_CMD_SET_CLK_STOP_MODE control command. */
typedef struct
{
	DCL_SIM_CLK_STOP mode;		/*the DCL_SIM_CLK_STOP structure, the structure is to tell the driver clock stop related information*/
} SIM_CTRL_SET_CLK_STOP_MODE_T;

/* FOR SIM_CTRL_CMD_TOUT_TEST control command. */
typedef struct
{
	DCL_UINT32 toutValue;			/*the tout value that we want to apply to TOUT test*/
} SIM_CTRL_TOUT_TEST_T;

/* FOR SIM_CTRL_CMD_GET_SPEED control command. */
typedef struct
{
	DCL_SIM_CARD_SPEED *speed; //return the card's speed to SIM task
} SIM_CTRL_GET_SPEED_T;

/* FOR SIM_CTRL_CMD_QUERY_9000_ON_SELECT control command. */
typedef struct
{
	DCL_BOOL *got9000; //return the information whether we encounter 9000 in select command
} SIM_CTRL_QUERY_9000_T;

/* FOR SIM_SLT_SET_RLT control command. */
typedef struct
{
	DCL_BOOL rlt; 			/*the SLT checking result set from protocol*/
} SIM_CTRL_SET_SLT_RLT_T;

/*dcl add new api : 5. add to DCL_CTRL_DATA enum*/

#ifdef __BUILD_DOM__
/*data structure union for all of SIM control commands*/
typedef union
{
   SIM_CTRL_RST_T		rSIMRst;															/*data structure for SIM_CTRL_CMD_RST control command*/
   SIM_CTRL_CMD_T		rSIMCmd;															/*data structure for SIM_CTRL_CMD_CMD control command*/
   SIM_CTRL_GET_CARD_INFO_T	rSIMGetCardInfo;							/*data structure for SIM_CTRL_CMD_GET_CARD_INFO control command*/
   SIM_CTRL_SET_MAX_SPEED_T	rSIMSetMaxSpeed;							/*data structure for SIM_CTRL_CMD_SET_SPEED control command*/
   SIM_CTRL_SET_PREFER_PROTOCOL_T	rSIMSetPreferProtocol;	/*data structure for SIM_CTRL_CMD_SET_PREFER_PROTOCOL control command*/
   SIM_CTRL_SET_CLK_STOP_MODE_T		rSIMSetClkStopMode;			/*data structure for SIM_CTRL_CMD_SET_CLK_STOP_MODE control command*/
   SIM_CTRL_TOUT_TEST_T		rSIMToutTest;										/*data structure for SIM_CTRL_CMD_TOUT_TEST control command*/
   SIM_CTRL_GET_SPEED_T		rSIMGetSpeed;										/*data structure for SIM_CTRL_CMD_GET_SPEED control command*/
   SIM_CTRL_QUERY_9000_T		rSIMQuery9000;								/*data structure for SIM_CTRL_CMD_QUERY_9000_ON_SELECT control command*/
   SIM_CTRL_SET_SLT_RLT_T		rSIMSetSltRlt;								/*data structure for SIM_CTRL_CMD_SET_SLT_RLT control command*/
}DCL_CTRL_DATA_T;
#else
#define SIM_CTRLS \
   SIM_CTRL_RST_T		rSIMRst; \
   SIM_CTRL_CMD_T		rSIMCmd; \
   SIM_CTRL_GET_CARD_INFO_T	rSIMGetCardInfo;\
   SIM_CTRL_SET_MAX_SPEED_T	rSIMSetMaxSpeed; \
   SIM_CTRL_SET_PREFER_PROTOCOL_T	rSIMSetPreferProtocol; \
   SIM_CTRL_SET_CLK_STOP_MODE_T		rSIMSetClkStopMode; \
   SIM_CTRL_TOUT_TEST_T		rSIMToutTest; \
   SIM_CTRL_GET_SPEED_T		rSIMGetSpeed; \
   SIM_CTRL_QUERY_9000_T		rSIMQuery9000; \
   SIM_CTRL_SET_SLT_RLT_T		rSIMSetSltRlt;   
#endif /*__BUILD_DOM__*/

#endif /*__DCL_SIM_H_STRUCT__*/

#endif /*DCL_DEFINITION_STRUCT*/

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_SIM_H_PROTOTYPE__
#define __DCL_SIM_H_PROTOTYPE__

/*************************************************************************
* FUNCTION
*  DclSIM_Open
* DESCRIPTION
*  This function is to open the SIM module and get a handle.
*
* PARAMETERS
*	dev: - only valid for DCL_SIM.
*	flags: - no sepcial flags is needed.
*
* RETURN VALUES
*	DCL_HANDLE_INVALID: - dev is an invalid value.
*	DCL_HANDLE_NONE: - no handler left, open failed.
* other value: - a valid handle
*
*************************************************************************/
DCL_HANDLE DclSIM_Open(DCL_DEV dev, DCL_FLAGS flags);

/*************************************************************************
* FUNCTION
*  DclSIM_Configure
*
* DESCRIPTION
*  This function is to configure the application usage of given handler.
*
* PARAMETERS
*	handle: - the handle to be configured, the value cannot be zero
* configure: - to configure the application usage of this card, possible value can be found in DCL_SIM_CONFIG_AP_TYPE
*
* RETURN VALUES 
*	STATUS_INVALID_DCL_HANDLE: - the handle is illegal
* STATUS_OK: - the configuration is done successfully
* STATUS_INVALID_CONFIGURATION: - the value of configure is not the one in DCL_SIM_CONFIG_AP_TYPE
*
*************************************************************************/
DCL_STATUS DclSIM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);

/*************************************************************************
* FUNCTION
*  DclSIM_Control
*
* DESCRIPTION
*  This function is the control command of SIM driver, this provides most of the SIM driver services to protocol.
*
* PARAMETERS
* handle: - a valid handle return by DclSIM_Open()
* cmd: 	  - a control command to SIM driver, possible values are as following
*         1.	SIM_CTRL_CMD_RST: try to reset the card and tell its existence
*         2.	SIM_CTRL_CMD_CMD: send APDU command to ICC/UICC
*         3.	SIM_CTRL_CMD_PWOFF: to power off the card
*         4.	SIM_CTRL_CMD_GET_CARD_INFO: to get the card information stored in driver layer
*         5.	SIM_CTRL_CMD_SET_SPEED: set the maximum allowed speed
*         6.	SIM_CTRL_CMD_SET_PREFER_PROTOCOL: to set the preferred physical protocl
*         7.	SIM_CTRL_CMD_SET_CLK_STOP_MODE: to set the clock stop related setting
*         8.	SIM_CTRL_CMD_TOUT_TEST: to start TOUT test, used by MEUT SIM test task
*         9.	SIM_CTRL_CMD_GET_SPEED: to get the card speed information
*         10.	SIM_CTRL_CMD_QUERY_9000_ON_SELECT: to querry whether 0x9000 after SELECT command happens
* data: - control data for SIM control command, possible values are as following
*          1. SIM_CTRL_CMD_RST: pointer to a SIM_CTRL_RST_T structure
*          1. SIM_CTRL_CMD_CMD: pointer to a SIM_CTRL_CMD_T structure
*          2. SIM_CTRL_CMD_PWOFF: NULL
*          3. SIM_CTRL_CMD_GET_CARD_INFO: pointer to a SIM_CTRL_GET_CARD_INFO_T structure
*          4. SIM_CTRL_CMD_SET_SPEED: pointer to a SIM_CTRL_SET_MAX_SPEED_T structure
*          5. SIM_CTRL_CMD_SET_PREFER_PROTOCOL: pointer to a SIM_CTRL_SET_PREFER_PROTOCOL_T structure
*          6. SIM_CTRL_CMD_SET_CLK_STOP_MODE: pointer to a SIM_CTRL_SET_CLK_STOP_MODE_T structure
*          7. SIM_CTRL_CMD_TOUT_TEST: pointer to a SIM_CTRL_TOUT_TEST_T structure
*          8. SIM_CTRL_CMD_GET_SPEED: pointer to a SIM_CTRL_GET_SPEED_T structure
*          9. SIM_CTRL_CMD_QUERY_9000_ON_SELECT: pointer to a SIM_CTRL_QUERY_9000_T structure
* RETURN VALUES
*	STATUS_OK: - command is executed successfully.
* STATUS_INVALID_CMD: - The command is invalid.
*************************************************************************/
DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*************************************************************************
* FUNCTION
*  DclSIM_Close
*
* DESCRIPTION
*  This function to close the further functionality of specified SIM handle.
*
* PARAMETERS
*	handle: the handle that return by DclSIM_Open.
*
* RETURN VALUES:
* STATUS_OK: - the handle is closed successfully
* STATUS_INVALID_DCL_HANDLE: - the handle is invalid
*	STATUS_UNSUPPORTED:
*
*************************************************************************/
DCL_STATUS DclSIM_Close(DCL_HANDLE handle);
DCL_STATUS DclSIM_Initialize(void);
#endif /*__DCL_SIM_H_PROTOTYPE__*/
#endif //DCL_DEFINITION_PROTOTYPE

