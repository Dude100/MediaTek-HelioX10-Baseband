/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   ccci_ch_cfg.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines the CCCI channels
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 08 01 2014 ap.wang
 * removed!
 * .
 *
 * removed!
 * removed!
 * [CCCI] CCCI new debug mechanism
 *
 * 05 14 2014 ap.wang
 * removed!
 * CCMNI Fast Ack Patch and linkdown fast reload
 *
 * removed!
 * removed!
 * 	[CCMNI ACK Fast Path]
 *
 * removed!
 * removed!
 * [CCCI] Add ICUSB feature.
 *
 * 11 26 2013 box.wu
 * removed!
 * add exception, tty, ICUSB.
 *
 * 05 30 2013 ap.wang
 * removed!
 * [CCCI_IMS] Add IMS_DCTRL channel
 *
 * 01 28 2013 ap.wang
 * removed!
 * [CCCI] CCCI_IMS channel rename
 *
 * removed!
 * removed!
 * [CCCI] CCCI_IMS 1st verison loopback support
 *
 * 01 11 2013 ap.wang
 * removed!
 * [CCCI] Modify CCCI channel config
 ****************************************************************************/
#ifndef _CCCI_CH_CFG_H
#define _CCCI_CH_CFG_H

/*!
 *  @brief CCCI_CHANNEL_T CCCI logical channel enum
 *            NOTICE: Negotiations With AP Owner Before Modification
 */

typedef enum
{
    CCCI_CONTROL_CHANNEL            = 0,
    CCCI_CONTROL_CHANNEL_ACK        = 1,
    CCCI_SYSTEM_CHANNEL             = 2,
    CCCI_SYSTEM_CHANNEL_ACK         = 3,
    CCCI_PCM_CHANNEL                = 4,
    CCCI_PCM_CHANNEL_ACK            = 5,
    CCCI_TST_CHANNEL                = 6,
    CCCI_TST_ACK_CHANNEL            = 7,
    CCCI_TR_CHANNEL                 = 8,
    CCCI_TR_ACK_CHANNEL             = 9,
    CCCI_AT_CHANNEL_TX              = 10,
    CCCI_AT_ACK_CHANNEL_TX          = 11,
    CCCI_AT_CHANNEL_RX              = 12,
    CCCI_AT_ACK_CHANNEL_RX          = 13,
    CCCI_FS_CHANNEL                 = 14,
    CCCI_FS_ACK_CHANNEL             = 15,
    CCCI_PMIC_CHANNEL               = 16,
    CCCI_PMIC_ACK_CHANNEL           = 17,
    CCCI_UEM_CHANNEL                = 18,
    CCCI_UEM_ACK_CHANNEL            = 19,
    CCCI_CCMNI1_RX                  = 20,
    CCCI_CCMNI1_RX_ACK              = 21,
    CCCI_CCMNI1_TX                  = 22,
    CCCI_CCMNI1_TX_ACK              = 23,
	CCCI_CCMNI2_RX                  = 24,
	CCCI_CCMNI2_RX_ACK              = 25,
	CCCI_CCMNI2_TX                  = 26,
	CCCI_CCMNI2_TX_ACK              = 27,
	CCCI_CCMNI3_RX                  = 28,
	CCCI_CCMNI3_RX_ACK              = 29,
	CCCI_CCMNI3_TX                  = 30,
	CCCI_CCMNI3_TX_ACK              = 31,
	CCCI_IPC_RPC_CHANNEL            = 32,
    CCCI_IPC_RPC_ACK_CHANNEL        = 33,
    CCCI_MSGSVC_SEND_CHANNEL        = 34,
    CCCI_MSGSVC_SEND_ACK_CHANNEL    = 35,
    CCCI_MSGSVC_RCV_CHANNEL         = 36,
    CCCI_MSGSVC_RCV_ACK_CHANNEL     = 37,
	CCCI_GPS_CHANNEL_TX             = 38,
    CCCI_GPS_ACK_CHANNEL_TX         = 39,
    CCCI_GPS_CHANNEL_RX             = 40,
    CCCI_GPS_ACK_CHANNEL_RX         = 41,
    CCCI_MD_LOG_RX                  = 42,
    CCCI_MD_LOG_TX                  = 43,
    CCCI_ARM7_RESERVED1_TX          = 44,
    CCCI_ARM7_RESERVED1_RX          = 45,
    CCCI_ARM7_RESERVED2_RX          = 46,
    CCCI_ARM7_RESERVED2_TX          = 47,
    CCCI_ARM7_RESERVED3_TX          = 48,
    CCCI_ARM7_RESERVED3_RX          = 49,
    CCCI_IT_CHANNEL_TX              = 50,
    CCCI_IT_CHANNEL_RX              = 51,
    CCCI_IMSV_UL                    = 52,
    CCCI_IMSV_DL                    = 53,
    CCCI_IMSC_UL                    = 54,
    CCCI_IMSC_DL                    = 55,
    CCCI_IMSA_UL                    = 56,
    CCCI_IMSA_DL                    = 57,
    CCCI_IMSD_UL                    = 58,
    CCCI_IMSD_DL                    = 59,
    CCCI_SIM_CHANNEL_TX             = 60,
    CCCI_SIM_CHANNEL_RX             = 61,
    CCCI_LB_IT_CHANNEL_TX           = 62,
    CCCI_LB_IT_CHANNEL_RX           = 63,
    CCCI_CCMNI1_DLACK_RX            = 64, //__CCMNI_ACK_FAST_PATH__
    CCCI_CCMNI2_DLACK_RX            = 65, //__CCMNI_ACK_FAST_PATH__
    CCCI_CCMNI3_DLACK_RX            = 66, //__CCMNI_ACK_FAST_PATH__   
    CCCI_DEBUG_STATUS_CHANNEL_TX    = 67,
    CCCI_DEBUG_STATUS_CHANNEL_RX    = 68,
    CCCI_CCMNI4_RX                  = 69,
	CCCI_CCMNI4_RX_ACK              = 70,
	CCCI_CCMNI4_TX                  = 71,
	CCCI_CCMNI4_TX_ACK              = 72,
	CCCI_CCMNI4_DLACK_RX            = 73, //__CCMNI_ACK_FAST_PATH__  
    CCCI_CCMNI5_RX                  = 74,
	CCCI_CCMNI5_RX_ACK              = 75,
	CCCI_CCMNI5_TX                  = 76,
	CCCI_CCMNI5_TX_ACK              = 77,
	CCCI_CCMNI5_DLACK_RX            = 78, //__CCMNI_ACK_FAST_PATH__  
    CCCI_CCMNI6_RX                  = 79,
	CCCI_CCMNI6_RX_ACK              = 80,
	CCCI_CCMNI6_TX                  = 81,
	CCCI_CCMNI6_TX_ACK              = 82,
	CCCI_CCMNI6_DLACK_RX            = 83, //__CCMNI_ACK_FAST_PATH__  
    CCCI_CCMNI7_RX                  = 84,
	CCCI_CCMNI7_RX_ACK              = 85,
	CCCI_CCMNI7_TX                  = 86,
	CCCI_CCMNI7_TX_ACK              = 87,
	CCCI_CCMNI7_DLACK_RX            = 88, //__CCMNI_ACK_FAST_PATH__  
    CCCI_CCMNI8_RX                  = 89,
	CCCI_CCMNI8_RX_ACK              = 90,
	CCCI_CCMNI8_TX                  = 91,
	CCCI_CCMNI8_TX_ACK              = 92,
	CCCI_CCMNI8_DLACK_RX            = 93, //__CCMNI_ACK_FAST_PATH__     
    CCCI_MAX_CHANNEL                = 94,
    CCCI_FORCE_RESET_MODEM_CHANNEL  = 20090215
} CCCI_CHANNEL_T;


#endif //#ifndef _CCCI_CH_CFG_H
