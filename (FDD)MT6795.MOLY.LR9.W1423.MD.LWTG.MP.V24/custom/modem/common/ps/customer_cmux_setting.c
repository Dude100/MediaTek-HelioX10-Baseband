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
 * customer_cmux_setting.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   This file is used to define the setting of CMUX.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __CMUX_SUPPORT__
/******************************************************************************/

/*========================================================================
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *
 *  Please DO NOT modify code below.
 *
 *  CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !! CAUTION !!
 *======================================================================= */

/******************************************************************************/

//#include "kal_release.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

/******************************************************************************/

#define CMUX_CONTROL_CHANNEL	0x00    // CMUX control channel
#define CMUX_DATA_CHANNEL       0x01 	// data channel 
#define CMUX_URC_CHANNEL        0x02    // indication channel (unsolicited code)
#define CMUX_CMD_CHANNEL        0x04    // AT command control
#define CMUX_CMD_URC_CHANNEL    0x06    // AT command control and unsolicited code
#define CMUX_NDIS_CHANNEL       0x08	// NDIS channel 
#define CMUX_VT_CHANNEL         0x10    // __VT_TRANSPORT_SUPPORT__
#define CMUX_CS_CHANNEL         0x20    // __DATA_CARD_SPEECH__

#define CMUX_CL1 	0x00      //  Type 1 -unstructured stream
#define CMUX_CL2 	0x01      //  Type 2 - unstructured stream with modem status
#define CMUX_CL3 	0x02      //  Type 3 - uninterruptible Framed Data
#define CMUX_CL4 	0x03      //  Type 4 - Interruptible  Framed data

#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold) 
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O)
#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG

/******************************************************************************/

static kal_uint8 g_channel_num = 
#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold) 1 +
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O)
	#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG
		0 ;

/******************************************************************************/

static kal_uint8 g_rx_buffer[
#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold) rxBuf +
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O)
	#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG
	0
];

static kal_uint8 g_tx_buffer[
#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold) txBuf +
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O)
	#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG
	0
];

/******************************************************************************/

typedef struct {

	kal_uint8 	channel_type;
	
    kal_uint32 	tx_buffer_size;

    kal_uint32 	rx_buffer_size;
    kal_uint32 	rx_low_threshold;
    kal_uint32 	rx_high_threshold;

	kal_uint8 *	tx_buffer;
	kal_uint8 *	rx_buffer;
	
}DlcBufStructT;

static DlcBufStructT g_dlc_buffer_config[] = {
#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold) \
		{ Type, txBuf, rxBuf, rxLThreshold, rxHThreshold, NULL, NULL },
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O)
	#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG
};

/******************************************************************************/

typedef struct {

    kal_uint8   dlci;		
	kal_uint8 	cltype;		
    kal_uint8   priority;
    kal_uint16  n1;
    module_type owner;
	
}DlcConfigStructT;

static DlcConfigStructT g_dlc_pn_config[] = {
#define CMUX_CH_BUFFER( Type, txBuf, rxBuf, rxLThreshold, rxHThreshold)
#define CMUX_CH_CONFIG( DLCI, CL, P, N1, O) { (DLCI), (CL), (P), (N1), (O)},
	#include "customer_cmux_setting.h"
#undef CMUX_CH_BUFFER
#undef CMUX_CH_CONFIG
};

/******************************************************************************/

kal_uint8* cmux_getDlcRxBuffer(kal_uint8 channel, kal_uint32 *size, 
	kal_uint32 *low_threshold, kal_uint32 *high_threshold)
{
	if( channel >= g_channel_num ) 
	{
		ASSERT(0);
	}

    *size = g_dlc_buffer_config[channel].rx_buffer_size;
    *low_threshold  = g_dlc_buffer_config[channel].rx_low_threshold;
    *high_threshold  = g_dlc_buffer_config[channel].rx_high_threshold;

	if ( g_dlc_buffer_config[channel].channel_type == CMUX_NDIS_CHANNEL ) 
	{
		*size = 0;	
    	return NULL;
	}
	else if( g_dlc_buffer_config[channel].rx_buffer == NULL )
	{
		kal_uint8 * rx_buf = g_rx_buffer;
		kal_uint8 	i;
	
		for(i=0;i<channel;i++)
			rx_buf += g_dlc_buffer_config[i].rx_buffer_size;
		g_dlc_buffer_config[channel].rx_buffer = rx_buf;
	}
    return g_dlc_buffer_config[channel].rx_buffer;
}

kal_uint8* cmux_getDlcTxBuffer( kal_uint8 channel, kal_uint32 *size)
{
	if( channel >= g_channel_num ) 
	{
		ASSERT(0);
	}

    *size = g_dlc_buffer_config[channel].tx_buffer_size;
	
	if ( g_dlc_buffer_config[channel].channel_type == CMUX_NDIS_CHANNEL ) 
	{
		*size = 0;
    	return NULL;
	}
	else if( g_dlc_buffer_config[channel].tx_buffer == NULL )
	{
		kal_uint8 * tx_buf = g_tx_buffer;
		kal_uint8 	i;
		
		for(i=0;i<channel;i++)
			tx_buf += g_dlc_buffer_config[i].tx_buffer_size;
		g_dlc_buffer_config[channel].tx_buffer = tx_buf;
	}
    return g_dlc_buffer_config[channel].tx_buffer;
}

kal_uint8 cmux_get_channel_def(kal_uint8 channel)
{
	if( channel >= g_channel_num ) 
	{
		ASSERT(0);
	}

    return g_dlc_buffer_config[channel].channel_type;
}

kal_bool cmux_custom_isPrePn(void)
{
    return CMUX_CHANNEL_PRE_PN;
}

kal_uint8 cmux_custom_getChannelDlci(kal_uint8 channel)
{
	if( (channel >= g_channel_num) || ( g_dlc_pn_config[channel].dlci > 32 )) 
	{
		ASSERT(0);
	}

    return g_dlc_pn_config[channel].dlci;
}

kal_uint8 cmux_custom_getChannelClType(kal_uint8 channel)
{
	if( channel >= g_channel_num || ( g_dlc_pn_config[channel].cltype == CMUX_CL3 ) ) 
	{
		ASSERT(0);
	}

	return g_dlc_pn_config[channel].cltype;
}

kal_uint8 cmux_custom_getChannelPriority(kal_uint8 channel)
{
	if( channel >= g_channel_num ) 
	{
		ASSERT(0);
	}

	return g_dlc_pn_config[channel].priority;
}

kal_uint16 cmux_custom_getChannelN1(kal_uint8 channel)
{
	if( channel >= g_channel_num || ( g_dlc_pn_config[channel].n1 < 16 ) 
        || ( g_dlc_pn_config[channel].n1 > 1510 ) ) 
	{
		ASSERT(0);
	}

	return g_dlc_pn_config[channel].n1;
}

module_type cmux_custom_getChannelOwner(kal_uint8 channel)
{
	if( channel >= g_channel_num ) 
	{
		ASSERT(0);
	}

	return g_dlc_pn_config[channel].owner;
}

/******************************************************************************/
#endif

