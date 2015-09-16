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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * customer_cmux_setting.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef CUSTOMER_CMUX_SETTING_H
#define CUSTOMER_CMUX_SETTING_H 
/******************************************************************************/

#include "global_def.h"

/******************************************************************************/

/*===================== Guideline of CMUX configuration ==========================

CMUX_CHANNEL_PRE_PN
>> This configuration refers to the following CMUX_CH_CONFIG taking effect or not

DEFAULT_XXX
>> These vaules are suggested settings of each channel type

CMUX_CH_BUFFER(	Channel Type, TX Buffer Size, RX Buffer Size, RX Low Threshold, RX High Threshold)
>> Config chanel type and buffer related configuration

CMUX_CH_CONFIG( DLCi, Convergence Layers Type, Priority, N1)
>> Pre-config CMUX DLC related parameters

========================================================================== */

/******************************************************************************/
                                                            
#if defined(__ANDROID_MODEM__) || defined(__MODEM_CARD__) || defined(__DUAL_TALK_MODEM_SUPPORT__)
#define CMUX_CHANNEL_PRE_PN			KAL_TRUE
#else
#define CMUX_CHANNEL_PRE_PN			KAL_FALSE
#endif

/******************************************************************************/

#define DEFAULT_N1 	512
#define DEFAULT_CL  CMUX_CL1

/******************************************************************************/

/* AT_CMD_CHANNEL */
#define DEFAULT_CMD_BUF_SIZE		    1024
#define DEFAULT_CMD_HIGH_THRESHOLD      512
#define DEFAULT_CMD_N1				    DEFAULT_N1
#define DEFAULT_CMD_CL 				    DEFAULT_CL

/* AT_DATA_CHANNEL */
#ifdef __MULTIPLE_PPP_DIALUP_SUPPORT__
#define DEFAULT_DATA_BUF_SIZE 		    32768
#define DEFAULT_DATA_HIGH_THRESHOLD     20480
#else
#define DEFAULT_DATA_BUF_SIZE 		    16384 	// WM_DUN_FLC, MAUI_01679336, mtk02285, 20090430
#define DEFAULT_DATA_HIGH_THRESHOLD     6144 
#endif
#define DEFAULT_DATA_N1 			    DEFAULT_N1
#define DEFAULT_DATA_CL 			    DEFAULT_CL

/* __VT_TRANSPORT_SUPPORT__ */
#define DEFAULT_VT_TX_BUFFER_SIZE       1281    //1281    // Jeffery 
#define DEFAULT_VT_RX_BUFFER_SIZE       1281    //1281
#define DEFAULT_VT_RX_LOW_THRESHOLD     320     //320
#define DEFAULT_VT_RX_HIGH_THRESHOLD    480     //480

/* __DATA_CARD_SPEECH__ */
#define DEFAULT_CS_BUFFER_SIZE          12289    //1024*12+1 
#define DEFAULT_CS_LOW_THRESHOLD        2048     //1024*2
#define DEFAULT_CS_HIGH_THRESHOLD       8192     //1024*8

/******************************************************************************/
#endif /* CUSTOMER_CMUX_SETTING_H */


/******************************************************************************/

/* CHANNEL_0 Settings */
CMUX_CH_BUFFER( CMUX_CONTROL_CHANNEL,	 256,  256, 0,  192 )
CMUX_CH_CONFIG( 0,  CMUX_CL1,  0, 512, MOD_NIL)

/******************************************************************************/

/* CHANNEL_1 Settings */
CMUX_CH_BUFFER( CMUX_DATA_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 1,  DEFAULT_DATA_CL, 20, DEFAULT_DATA_N1, MOD_ATCI)

/* CHANNEL_2 Settings */
#ifdef __MULTIPLE_PPP_DIALUP_SUPPORT__
CMUX_CH_BUFFER( CMUX_URC_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 2,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)
#else
CMUX_CH_BUFFER( CMUX_URC_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 2,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)
#endif

/* CHANNEL_3 Settings */
#ifdef __MULTIPLE_PPP_DIALUP_SUPPORT__
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 3,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)
#else
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 3,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)
#endif

#if defined(__ANDROID_MODEM__) || defined(__DUAL_TALK_MODEM_SUPPORT__) || defined(__EIGHT_PORT_MODULE__)
/* CHANNEL_4 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 4,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)

/* CHANNEL_5 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 5,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)
#endif

/******************************************************************************/

#if defined(__GEMINI__) || defined(__SGLTE__)

/******************************************************************************/

#if ( MAX_SIM_NUM > 1 )

/* CHANNEL_6 Settings */
CMUX_CH_BUFFER( CMUX_DATA_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 6,  DEFAULT_DATA_CL, 20, DEFAULT_DATA_N1, MOD_ATCI+1)

/* CHANNEL_7 Settings */
CMUX_CH_BUFFER( CMUX_URC_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 7,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+1)

/* CHANNEL_8 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 8,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+1)

#if defined(__ANDROID_MODEM__) || defined(__DUAL_TALK_MODEM_SUPPORT__) || defined(__EIGHT_PORT_MODULE__)
/* CHANNEL_9 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 9,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+1)

/* CHANNEL_10 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 10,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+1)
#endif

#endif

/******************************************************************************/

#if ( MAX_SIM_NUM > 2 )

/* CHANNEL_11 Settings */
CMUX_CH_BUFFER( CMUX_DATA_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 11,  DEFAULT_DATA_CL, 20, DEFAULT_DATA_N1, MOD_ATCI+2)

/* CHANNEL_12 Settings */
CMUX_CH_BUFFER( CMUX_URC_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 12,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+2)

/* CHANNEL_13 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 13,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+2)

#if defined(__ANDROID_MODEM__) || defined(__DUAL_TALK_MODEM_SUPPORT__) || defined(__EIGHT_PORT_MODULE__)
/* CHANNEL_14 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 14,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+2)

/* CHANNEL_15 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 15,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+2)
#endif

#endif

/******************************************************************************/

#if ( MAX_SIM_NUM > 3 )

/* CHANNEL_16 Settings */
CMUX_CH_BUFFER( CMUX_DATA_CHANNEL, DEFAULT_DATA_BUF_SIZE, DEFAULT_DATA_BUF_SIZE, 0, DEFAULT_DATA_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 16,  DEFAULT_DATA_CL, 20, DEFAULT_DATA_N1, MOD_ATCI+3)

/* CHANNEL_17 Settings */
CMUX_CH_BUFFER( CMUX_URC_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 17,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+3)

/* CHANNEL_18 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 18,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+3)

#if defined(__ANDROID_MODEM__) || defined(__DUAL_TALK_MODEM_SUPPORT__) || defined(__EIGHT_PORT_MODULE__)
/* CHANNEL_19 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 19,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+3)

/* CHANNEL_20 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 20,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+3)
#endif

#endif

/******************************************************************************/

#endif /* __GEMINI__ || __MMDC_DS__ */ 

/******************************************************************************/

/* CHANNEL_24 Settings */
#ifdef __VT_TRANSPORT_SUPPORT__
#if !defined(__WM_RIL_SUPPORT__) || !defined(__GEMINI__)
CMUX_CH_BUFFER( CMUX_VT_CHANNEL, DEFAULT_VT_TX_BUFFER_SIZE, DEFAULT_VT_RX_BUFFER_SIZE, DEFAULT_VT_RX_LOW_THRESHOLD, DEFAULT_VT_RX_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 24,  DEFAULT_CL, 15, DEFAULT_N1, MOD_VT) // DLCI=24, Priority=15 (between CMD and DATA)
#endif
#endif /* __VT_TRANSPORT_SUPPORT__ */

/******************************************************************************/

/* CHANNEL_25 Settings */
#ifdef __DATA_CARD_SPEECH__
CMUX_CH_BUFFER( CMUX_CS_CHANNEL, DEFAULT_CS_BUFFER_SIZE, DEFAULT_CS_BUFFER_SIZE, DEFAULT_CS_LOW_THRESHOLD, DEFAULT_CS_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 25,  DEFAULT_CL, 16, DEFAULT_N1, MOD_MED)
#endif /* __DATA_CARD_SPEECH__ */

/******************************************************************************/

/* CHANNEL_26 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 26,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI)

#if defined(__GEMINI__) || defined(__SGLTE__)
#if ( MAX_SIM_NUM > 1 )
/* CHANNEL_27 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 27,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+1)
#endif

#if ( MAX_SIM_NUM > 2 )
/* CHANNEL_28 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 28,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+2)
#endif

#if ( MAX_SIM_NUM > 3 )
/* CHANNEL_29 Settings */
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CMD_BUF_SIZE,  DEFAULT_CMD_BUF_SIZE, 0,  DEFAULT_CMD_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 29,  DEFAULT_CMD_CL,  10, DEFAULT_CMD_N1, MOD_ATCI+3)
#endif
#endif /* __GEMINI__ */

/******************************************************************************/

/* CHANNEL_30 Settings */
#if defined(__CSD_NT__) || defined(__CSD_T__) 
CMUX_CH_BUFFER( CMUX_CMD_CHANNEL,  DEFAULT_CS_BUFFER_SIZE,  DEFAULT_CS_BUFFER_SIZE, DEFAULT_CS_LOW_THRESHOLD,  DEFAULT_CS_HIGH_THRESHOLD )
CMUX_CH_CONFIG( 30,  DEFAULT_CL,  17, DEFAULT_N1, MOD_ATCI)
#endif /* __CSD_NT__ || __CSD_T__ */

/******************************************************************************/
